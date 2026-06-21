#include<bits/stdc++.h>
#undef UNICODE
#undef _UNICODE
#include<windows.h>
using namespace std;
const int N=100,CELL=14,VW=720,VH=720,W=VW+230,H=VH+30;

int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
int g[N][N],dir,sdir,score,len,ti;
deque<pair<int,int>> body,prevBody;
bool run,menu=1;
int hi,enemyN=2,dead,deathStart;
float p,camX,camY,prevCamX,prevCamY,zoom=1.0f;

// Q-learning
float Q[72][3];
int totalGames;
float lr=0.15f,discount=0.9f;

vector<string> allNames={"Steve","Alex","Herobrine","Notch","Creeper","Enderman",
"Zombie","Skeleton","Spider","Piglin","Blaze","Ghast","Wither","Dragon",
"Villager","Golem","Wolf","Cat","Fox","Bee","Slime","Warden","Axolotl","Goat"};
string myName;

struct Enemy
{
    deque<pair<int,int>> body;
    int dir,prevS,prevA;
    string name;
};
vector<Enemy> enemy;
vector<pair<int,int>> food;

float epsilon()
{
    return max(0.02f,1.0f-totalGames*0.02f);
}

int sign(int x){return x>0?1:(x<0?-1:0);}

int getState(int hx,int hy,int hd,deque<pair<int,int>>& b)
{
    int dl=(hd+3)%4,dr=(hd+1)%4;
    auto blocked=[&](int x,int y){
        if(x<0||x>=N||y<0||y>=N)return 1;
        if(g[y][x]==1)return 1;
        for(auto& e:enemy)for(auto [ex,ey]:e.body)if(ex==x&&ey==y)return 1;
        for(int j=0;j<(int)b.size()-1;j++)if(b[j].first==x&&b[j].second==y)return 1;
        return 0;
    };
    int da=blocked(hx+dx[hd],hy+dy[hd]);
    int dlb=blocked(hx+dx[dl],hy+dy[dl]);
    int drb=blocked(hx+dx[dr],hy+dy[dr]);
    // nearest food
    int tfx=N/2,tfy=N/2,md=N*N;
    for(auto [ffx,ffy]:food){int d=abs(ffx-hx)+abs(ffy-hy);if(d<md){md=d;tfx=ffx;tfy=ffy;}}
    int fdx=sign(tfx-hx),fdy=sign(tfy-hy);
    int fd=(fdx+1)*3+(fdy+1);
    // absolute direction mapping to relative
    // fd encodes dx,dy as: (fdx+1)*3+(fdy+1) which is 0..8
    // We want food_dir relative to heading (0=ahead,1=left,2=right,3=behind)
    int fdxa[]={0,0,0,1,1,1,-1,-1,-1};
    int fdya[]={-1,0,1,-1,0,1,-1,0,1};
    // map absolute food direction to relative
    // For each heading direction, the relative directions are:
    // hd=0(up):   ahead=(0,-1), left=(-1,0), right=(1,0), behind=(0,1)
    // hd=1(right): ahead=(1,0), left=(0,-1), right=(0,1), behind=(-1,0)
    // hd=2(down): ahead=(0,1), left=(1,0), right=(-1,0), behind=(0,-1)
    // hd=3(left): ahead=(-1,0), left=(0,1), right=(0,-1), behind=(1,0)
    int relDirs[4][4][2]={
        {{0,-1},{-1,0},{1,0},{0,1}},
        {{1,0},{0,-1},{0,1},{-1,0}},
        {{0,1},{1,0},{-1,0},{0,-1}},
        {{-1,0},{0,1},{0,-1},{1,0}}
    };
    int foodRel=3; // default behind
    for(int r=0;r<4;r++){if(relDirs[hd][r][0]==fdx&&relDirs[hd][r][1]==fdy){foodRel=r;break;}}
    return ((da*2+dlb)*2+drb)*4+foodRel;
}

void saveQ()
{
    ofstream f("snake_ai.dat",ios::binary);
    f.write((char*)Q,sizeof(Q));
    f.write((char*)&totalGames,sizeof(totalGames));
}

void loadQ()
{
    ifstream f("snake_ai.dat",ios::binary);
    if(f){f.read((char*)Q,sizeof(Q));f.read((char*)&totalGames,sizeof(totalGames));}
    else{memset(Q,0,sizeof(Q));totalGames=0;}
}

void spawnFood()
{
    for(int i=0;i<20;i++)
    {
        int fx=rand()%N,fy=rand()%N;
        if(g[fy][fx])continue;
        bool bad=0;
        for(auto [ex,ey]:body)if(ex==fx&&ey==fy){bad=1;break;}
        if(bad)continue;
        for(auto& e:enemy)for(auto [ex,ey]:e.body)if(ex==fx&&ey==fy){bad=1;break;}
        if(bad)continue;
        food.push_back({fx,fy});g[fy][fx]=2;return;
    }
}

void spawnFoodAt(int x,int y)
{
    if(x<0||x>=N||y<0||y>=N)return;
    if(g[y][x])return;
    for(auto [fx,fy]:food)if(fx==x&&fy==y)return;
    for(auto [bx,by]:body)if(bx==x&&by==y)return;
    for(auto& e:enemy)for(auto [ex,ey]:e.body)if(ex==x&&ey==y)return;
    food.push_back({x,y});g[y][x]=2;
}

void dropFood(deque<pair<int,int>>& b)
{
    for(auto [bx,by]:b){g[by][bx]=0;spawnFoodAt(bx,by);}
}

void spawnEnemy()
{
    for(int att=0;att<20;att++)
    {
        int edge=rand()%4,ex,ey,ed,off=4;
        if(edge==0){ex=rand()%N;ey=off;ed=2;}
        else if(edge==1){ex=rand()%N;ey=N-1-off;ed=0;}
        else if(edge==2){ex=off;ey=rand()%N;ed=1;}
        else{ex=N-1-off;ey=rand()%N;ed=3;}
        int elen=rand()%2+2;
        deque<pair<int,int>> eb;
        bool bad=0;
        for(int i=0;i<elen;i++)
        {
            int px=ex-i*dx[ed],py=ey-i*dy[ed];
            if(px<0||px>=N||py<0||py>=N){bad=1;break;}
            if(g[py][px]==1){bad=1;break;}
            for(auto& e:enemy)for(auto [bx,by]:e.body)if(bx==px&&by==py){bad=1;break;}
            if(bad)break;
            eb.push_back({px,py});
        }
        if(bad||(int)eb.size()<2)continue;
        string nm=allNames[rand()%allNames.size()];
        enemy.push_back({eb,ed,-1,-1,nm});
        return;
    }
}

void respawnPlayer()
{
    for(auto [bx,by]:body)g[by][bx]=0;
    body.clear();
    int edge=rand()%4,ex,ey,ed,off=5;
    if(edge==0){ex=rand()%N;ey=off;ed=2;}
    else if(edge==1){ex=rand()%N;ey=N-1-off;ed=0;}
    else if(edge==2){ex=off;ey=rand()%N;ed=1;}
    else{ex=N-1-off;ey=rand()%N;ed=3;}
    len=3;dir=ed;sdir=ed;
    for(int i=0;i<len;i++)
    {
        int px=ex-i*dx[ed],py=ey-i*dy[ed];
        if(px<0||px>=N||py<0||py>=N){px=ex;py=ey;}
        body.push_back({px,py});g[py][px]=1;
    }
    prevBody=body;
    camX=prevCamX=body.front().first;camY=prevCamY=body.front().second;
    dead=0;deathStart=0;run=1;
}

bool atEnemy(int x,int y)
{
    for(auto& e:enemy)for(auto [ex,ey]:e.body)if(ex==x&&ey==y)return 1;
    return 0;
}

void init(HWND hw=0)
{
    memset(g,0,sizeof(g));
    body.clear();prevBody.clear();enemy.clear();food.clear();
    len=3; dir=1; sdir=1; score=0; run=1; ti=70; p=0; dead=0; deathStart=0;
    zoom=1.0f;
    int ni=rand()%allNames.size();
    myName=allNames[ni];
    for(int i=0;i<len;i++){body.push_back({N/2-i,N/2});g[N/2][N/2-i]=1;}
    prevBody=body;
    camX=prevCamX=N/2;camY=prevCamY=N/2;
    srand(time(0)+(int)GetTickCount());
    totalGames++;
    for(int i=0;i<enemyN;i++)spawnEnemy();
    for(int i=0;i<5+enemyN;i++)spawnFood();
    if(hw){SetTimer(hw,1,16,NULL);}
}

void tick(HWND hw)
{
    if(menu||dead||!run)return;
    prevBody=body;
    prevCamX=camX;prevCamY=camY;
    dir=sdir;
    auto [x,y]=body.front();
    int nx=x+dx[dir],ny=y+dy[dir];
    if(nx<0||nx>=N||ny<0||ny>=N){dead=1;deathStart=GetTickCount();dropFood(body);for(auto [bx,by]:body)g[by][bx]=0;body.clear();goto end;}
    if(g[ny][nx]==1){dead=1;deathStart=GetTickCount();dropFood(body);for(auto [bx,by]:body)g[by][bx]=0;body.clear();goto end;}
    if(atEnemy(nx,ny)){dead=1;deathStart=GetTickCount();dropFood(body);for(auto [bx,by]:body)g[by][bx]=0;body.clear();goto end;}
    {int ate=0;
    for(int i=0;i<(int)food.size();i++){if(food[i].first==nx&&food[i].second==ny){g[ny][nx]=0;food.erase(food.begin()+i);ate=1;break;}}
    body.push_front({nx,ny});
    g[ny][nx]=1;
    if(!ate){auto [tx,ty]=body.back();g[ty][tx]=0;body.pop_back();}
    else{score++;len++;ti=max(30,70-score);spawnFood();}}
    camX=body.front().first;camY=body.front().second;

    // enemies with Q-learning
    for(int ei=0;ei<(int)enemy.size();ei++)
    {
        auto& e=enemy[ei];
        auto [ehx,ehy]=e.body.front();

        // get current state & choose action
        int s=getState(ehx,ehy,e.dir,e.body);
        int action;
        float eps=epsilon();
        if((float)rand()/RAND_MAX<eps){action=rand()%3;}
        else{
            float bq=Q[s][0];int ba=0;
            for(int a=1;a<3;a++){if(Q[s][a]>bq){bq=Q[s][a];ba=a;}}
            action=ba;
        }

        // compute new dir from action (0=left,1=straight,2=right)
        int nd;
        if(action==0)nd=(e.dir+3)%4;
        else if(action==1)nd=e.dir;
        else nd=(e.dir+1)%4;

        // compute new head position
        int enx=ehx+dx[nd],eny=ehy+dy[nd];

        // check wall
        if(enx<0||enx>=N||eny<0||eny>=N)
        {
            // Q update: death = -100
            if(e.prevS>=0)
            {
                float td=-100-Q[e.prevS][e.prevA];
                Q[e.prevS][e.prevA]+=lr*td;
            }
            dropFood(e.body);enemy.erase(enemy.begin()+ei);ei--;spawnEnemy();spawnFood();continue;
        }
        // check player body
        if(g[eny][enx]==1)
        {
            score+=2;
            if(e.prevS>=0)
            {
                float td=-100-Q[e.prevS][e.prevA];
                Q[e.prevS][e.prevA]+=lr*td;
            }
            dropFood(e.body);enemy.erase(enemy.begin()+ei);ei--;spawnEnemy();spawnFood();continue;
        }
        // check other enemies / own body
        bool hit=0;
        for(int j=0;j<(int)enemy.size();j++)if(j!=ei)for(auto [ex,ey]:enemy[j].body)if(ex==enx&&ey==eny){hit=1;break;}
        if(!hit)for(int j=0;j<(int)e.body.size()-1;j++)if(e.body[j].first==enx&&e.body[j].second==eny){hit=1;break;}
        if(hit)
        {
            if(e.prevS>=0)
            {
                float td=-100-Q[e.prevS][e.prevA];
                Q[e.prevS][e.prevA]+=lr*td;
            }
            dropFood(e.body);enemy.erase(enemy.begin()+ei);ei--;spawnEnemy();spawnFood();continue;
        }

        // move is valid - store Q update
        e.body.push_front({enx,eny});
        int ate=0;
        for(int i=0;i<(int)food.size();i++){if(food[i].first==enx&&food[i].second==eny){g[food[i].second][food[i].first]=0;food.erase(food.begin()+i);ate=1;break;}}
        if(ate){spawnFood();}
        else{e.body.pop_back();}

        int ns=getState(enx,eny,nd,e.body);
        float maxQ=max({Q[ns][0],Q[ns][1],Q[ns][2]});
        float reward=ate?10.0f:-0.1f;
        if(e.prevS>=0)
        {
            float td=reward+discount*maxQ-Q[e.prevS][e.prevA];
            Q[e.prevS][e.prevA]+=lr*td;
        }
        e.prevS=s;e.prevA=action;
        e.dir=nd;
    }
    while((int)food.size()<5+(int)enemy.size())spawnFood();

end:
    if(dead)
    {
        saveQ();
        if(score>hi){hi=score;ofstream("snake_hi.dat",ios::binary).write((char*)&hi,sizeof(hi));}
    }
}

void drawSnake(HDC h,float cix,float ciy,float cs,int mg,
    deque<pair<int,int>>& b,deque<pair<int,int>>& pb,float ip,
    int d,int r,int gr,int b2,int pr,int pg,int pb2,
    const string& nm="")
{
    HBRUSH hb=CreateSolidBrush(RGB(r,gr,b2));
    HPEN hp=CreatePen(PS_SOLID,2,RGB(pr,pg,pb2));
    SelectObject(h,hb);SelectObject(h,hp);
    int idx=0;
    int gx0=max(0,(int)(cix-VW/2/cs-1)),gx1=min(N,(int)(cix+VW/2/cs+2));
    int gy0=max(0,(int)(ciy-VH/2/cs-1)),gy1=min(N,(int)(ciy+VH/2/cs+2));
    for(auto [x,y]:b)
    {
        if(x<gx0||x>gx1||y<gy0||y>gy1){idx++;continue;}
        float px,py;
        if(idx<(int)pb.size()){px=pb[idx].first+(x-pb[idx].first)*ip;py=pb[idx].second+(y-pb[idx].second)*ip;}
        else{px=x;py=y;}
        int sx=(int)((px-cix)*cs+VW/2);
        int sy=(int)((py-ciy)*cs+VH/2+mg);
        RoundRect(h,sx+2,sy+2,sx+(int)cs-2,sy+(int)cs-2,5,5);
        idx++;
    }
    DeleteObject(hb);DeleteObject(hp);

    if(b.empty())return;
    auto [hx,hy]=b.front();
    float hpx=pb[0].first+(hx-pb[0].first)*ip;
    float hpy=pb[0].second+(hy-pb[0].second)*ip;
    int hsx=(int)((hpx-cix)*cs+VW/2);
    int hsy=(int)((hpy-ciy)*cs+VH/2+mg);
    HBRUSH hhead=CreateSolidBrush(RGB(min(255,r+30),min(255,gr+30),min(255,b2+30)));
    SelectObject(h,hhead);
    RoundRect(h,hsx+2,hsy+2,hsx+(int)cs-2,hsy+(int)cs-2,5,5);
    DeleteObject(hhead);

    int cex=hsx+(int)cs/2,cey=hsy+(int)cs/2;
    int eo=(int)(cs*0.22f),ed=(int)(cs*0.35f);
    int ex1=cex-eo+(dx[d]*ed),ey1=cey-eo+(dy[d]*ed);
    int ex2=cex+eo+(dx[d]*ed),ey2=cey-eo+(dy[d]*ed);
    int es=max(3,(int)(cs*0.3f));
    HBRUSH hey=CreateSolidBrush(RGB(255,255,255));
    SelectObject(h,hey);
    Ellipse(h,ex1,ey1,ex1+es,ey1+es);
    Ellipse(h,ex2,ey2,ex2+es,ey2+es);
    HBRUSH hpup=CreateSolidBrush(RGB(0,0,0));
    SelectObject(h,hpup);
    int ps2=es*2/3;
    Ellipse(h,ex1+1,ey1+1,ex1+ps2,ey1+ps2);
    Ellipse(h,ex2+1,ey2+1,ex2+ps2,ey2+ps2);
    DeleteObject(hpup);
    DeleteObject(hey);

    if(!nm.empty()&&cs>10)
    {
        HFONT hfn=CreateFont(max(10,(int)(cs*0.5f)),0,0,0,0,0,0,0,0,0,0,0,0,"微软雅黑");
        SelectObject(h,hfn);
        SetTextColor(h,RGB(255,255,255));
        int nw=nm.size()*cs*0.3f;
        TextOutA(h,hsx+(int)cs/2-nw/2,hsy-(int)(cs*0.4f),nm.c_str(),nm.size());
        DeleteObject(hfn);
    }
}

void draw(HDC h,HWND hw=0)
{
    RECT rc;
    if(hw){GetClientRect(hw,&rc);}
    else{rc.left=0;rc.top=0;rc.right=W;rc.bottom=H;}
    HBRUSH hb=CreateSolidBrush(RGB(22,24,34));
    FillRect(h,&rc,hb);DeleteObject(hb);
    SetBkMode(h,TRANSPARENT);

    if(menu)
    {
        HFONT hft=CreateFont(72,0,0,0,0,0,0,0,0,0,0,0,0,"微软雅黑");
        SelectObject(h,hft);
        SetTextColor(h,RGB(220,50,50));
        TextOutA(h,VW/2-130,VH/2-130,"贪吃蛇",9);
        DeleteObject(hft);

        HFONT hfs=CreateFont(22,0,0,0,0,0,0,0,0,0,0,0,0,"微软雅黑");
        SelectObject(h,hfs);
        SetTextColor(h,RGB(180,180,190));
        TextOutA(h,VW/2-100,VH/2-20,"敌蛇数量:",10);
        SetTextColor(h,RGB(100,150,255));
        TextOutA(h,VW/2+60,VH/2-22,"<",1);
        char nb[16];sprintf(nb,"%d",enemyN);
        SetTextColor(h,RGB(220,220,230));
        TextOutA(h,VW/2+85,VH/2-22,nb,strlen(nb));
        SetTextColor(h,RGB(100,150,255));
        TextOutA(h,VW/2+108,VH/2-22,">",1);

        SetTextColor(h,RGB(150,150,160)+RGB(20,20,0)*(int)(sin(GetTickCount()*0.003f)*10));
        TextOutA(h,VW/2-85,VH/2+30,"按空格开始",10);

        SetTextColor(h,RGB(100,100,110));
        TextOutA(h,VW/2-90,VH/2+65,"方向键 移动",11);
        TextOutA(h,VW/2-64,VH/2+90,"滚轮 缩放",10);
        SetTextColor(h,RGB(180,180,190));
        string hhs="最高分: "+to_string(hi);
        TextOutA(h,VW/2-70,VH/2+125,hhs.c_str(),hhs.size());
        DeleteObject(hfs);
        return;
    }

    float cix=prevCamX+(camX-prevCamX)*p;
    float ciy=prevCamY+(camY-prevCamY)*p;
    float cs=CELL*zoom;int mg=8;
    int gx0=max(0,(int)(cix-VW/2/cs-1));
    int gx1=min(N,(int)(cix+VW/2/cs+2));
    int gy0=max(0,(int)(ciy-VH/2/cs-1));
    int gy1=min(N,(int)(ciy+VH/2/cs+2));

    // grid
    HPEN hp=CreatePen(PS_SOLID,1,RGB(45,50,65));
    SelectObject(h,hp);
    for(int i=gx0;i<=gx1;i++){int sx=(int)((i-cix)*cs+VW/2);MoveToEx(h,sx,mg,NULL);LineTo(h,sx,VH+mg);}
    for(int i=gy0;i<=gy1;i++){int sy=(int)((i-ciy)*cs+VH/2+mg);MoveToEx(h,mg,sy,NULL);LineTo(h,VW+mg,sy);}
    DeleteObject(hp);

    // food
    HBRUSH hfood=CreateSolidBrush(RGB(255,180,40));
    HPEN pfood=CreatePen(PS_SOLID,0,RGB(255,180,40));
    SelectObject(h,hfood);SelectObject(h,pfood);
    for(auto [fx,fy]:food)
    {
        if(fx<gx0||fx>gx1||fy<gy0||fy>gy1)continue;
        int fsx=(int)((fx-cix)*cs+VW/2);
        int fsy=(int)((fy-ciy)*cs+VH/2+mg);
        Ellipse(h,fsx+2,fsy+2,fsx+(int)cs-2,fsy+(int)cs-2);
    }
    DeleteObject(hfood);DeleteObject(pfood);

    // enemies
    for(auto& e:enemy)drawSnake(h,cix,ciy,cs,mg,e.body,e.body,0,e.dir,200,40,40,160,20,20,e.name);

    // player
    if(!body.empty())drawSnake(h,cix,ciy,cs,mg,body,prevBody,p,dir,220,50,50,180,30,30,dead?"":myName);

    // minimap
    int mmx=VW+25,mmy=VH-155,mms=150;
    HPEN hpmm=CreatePen(PS_SOLID,1,RGB(60,60,80));
    SelectObject(h,hpmm);
    HBRUSH hbmm=CreateSolidBrush(RGB(15,17,27));
    SelectObject(h,hbmm);
    RoundRect(h,mmx,mmy,mmx+mms,mmy+mms,6,6);
    DeleteObject(hbmm);
    float ms=mms/(float)N;
    HPEN hpvp=CreatePen(PS_SOLID,1,RGB(100,120,200));
    SelectObject(h,hpvp);
    int vpx=mmx+(int)((cix-VW/2/cs)*ms);
    int vpy=mmy+(int)((ciy-VH/2/cs)*ms);
    int vpw=(int)(VW/cs*ms);
    int vph=(int)(VH/cs*ms);
    if(vpw>0&&vph>0)Rectangle(h,vpx,vpy,vpx+vpw,vpy+vph);
    DeleteObject(hpvp);
    HPEN hpe=CreatePen(PS_SOLID,1,RGB(200,40,40));
    SelectObject(h,hpe);
    for(auto& e:enemy)for(auto [bx,by]:e.body){int bpx=mmx+(int)(bx*ms),bpy=mmy+(int)(by*ms);Rectangle(h,bpx,bpy,bpx+2,bpy+2);}
    DeleteObject(hpe);
    HPEN hpsn=CreatePen(PS_SOLID,1,RGB(220,50,50));
    SelectObject(h,hpsn);
    for(auto [bx,by]:body){int bpx=mmx+(int)(bx*ms),bpy=mmy+(int)(by*ms);Rectangle(h,bpx,bpy,bpx+2,bpy+2);}
    DeleteObject(hpsn);
    HBRUSH hbf=CreateSolidBrush(RGB(255,180,40));
    HPEN hpf=CreatePen(PS_SOLID,0,RGB(255,180,40));
    SelectObject(h,hbf);SelectObject(h,hpf);
    for(auto [fpx,fpy]:food){int fmx=mmx+(int)(fpx*ms),fmy=mmy+(int)(fpy*ms);Ellipse(h,fmx,fmy,fmx+3,fmy+3);}
    DeleteObject(hbf);DeleteObject(hpf);
    DeleteObject(hpmm);

    // info panel
    HFONT hf=CreateFont(24,0,0,0,0,0,0,0,0,0,0,0,0,"微软雅黑");
    SelectObject(h,hf);
    int xx=VW+25,yy=20;
    SetTextColor(h,RGB(200,200,200));
    string d="分数: "+to_string(score);TextOutA(h,xx,yy,d.c_str(),d.size());yy+=35;
    string hhs="最高: "+to_string(hi);TextOutA(h,xx,yy,hhs.c_str(),hhs.size());yy+=35;
    string l="长度: "+to_string(len);TextOutA(h,xx,yy,l.c_str(),l.size());yy+=50;
    SetTextColor(h,RGB(120,120,140));
    TextOutA(h,xx,yy,"方向键 移动",11);yy+=35;
    SetTextColor(h,RGB(80,80,100));
    TextOutA(h,xx,yy,"[R] 重开",9);yy+=22;
    TextOutA(h,xx,yy,"[P] 暂停",9);yy+=22;
    TextOutA(h,xx,yy,"[ESC] 退出",10);yy+=35;
    TextOutA(h,xx,yy,"滚轮 缩放",10);yy+=22;
    char zb[32];sprintf(zb,"%.0f%%",zoom*100);
    TextOutA(h,xx,yy,zb,strlen(zb));
    if(dead)
    {
        int el=(int)(GetTickCount()-deathStart);
        SetTextColor(h,RGB(255,80,80));
        HFONT hf2=CreateFont(36,0,0,0,0,0,0,0,0,0,0,0,0,"微软雅黑");
        SelectObject(h,hf2);
        if(el<5000){char dtb[32];sprintf(dtb,"%d",(5000-el)/1000+1);TextOutA(h,VW/2-50,VH/2-20,dtb,strlen(dtb));}
        else{TextOutA(h,VW/2-110,VH/2-20,"按空格重新进入",14);}
        DeleteObject(hf2);
    }
    if(!run&&!dead)
    {
        SetTextColor(h,RGB(255,200,80));
        HFONT hf2=CreateFont(36,0,0,0,0,0,0,0,0,0,0,0,0,"微软雅黑");
        SelectObject(h,hf2);
        TextOutA(h,VW/2-44,VH/2-20,"已暂停",6);
        DeleteObject(hf2);
    }
    DeleteObject(hf);
}

LRESULT CALLBACK WndProc(HWND hw,UINT msg,WPARAM w,LPARAM l)
{
    if(msg==WM_DESTROY){saveQ();PostQuitMessage(0);return 0;}
    if(msg==WM_ERASEBKGND){return 1;}
    if(msg==WM_MOUSEWHEEL)
    {
        if(!menu){int d=GET_WHEEL_DELTA_WPARAM(w);zoom*=d>0?1.15f:0.87f;zoom=max(0.2f,min(5.0f,zoom));InvalidateRect(hw,0,TRUE);}
        return 0;
    }
    if(msg==WM_PAINT)
    {
        PAINTSTRUCT ps;HDC hdc=BeginPaint(hw,&ps);
        RECT rc;GetClientRect(hw,&rc);
        HDC mem=CreateCompatibleDC(hdc);
        HBITMAP bm=CreateCompatibleBitmap(hdc,rc.right,rc.bottom);
        SelectObject(mem,bm);
        draw(mem,hw);
        BitBlt(hdc,0,0,rc.right,rc.bottom,mem,0,0,SRCCOPY);
        DeleteObject(bm);DeleteDC(mem);
        EndPaint(hw,&ps);
        return 0;
    }
    if(msg==WM_KEYDOWN)
    {
        if(menu)
        {
            if(w==VK_LEFT&&enemyN>0){enemyN--;InvalidateRect(hw,0,TRUE);}
            else if(w==VK_RIGHT&&enemyN<9){enemyN++;InvalidateRect(hw,0,TRUE);}
            else if(w==VK_SPACE){menu=0;init(hw);InvalidateRect(hw,0,TRUE);}
            return 0;
        }
        if(dead)
        {
            if(GetTickCount()-deathStart>=5000&&w==VK_SPACE){respawnPlayer();InvalidateRect(hw,0,TRUE);}
            return 0;
        }
        if(w==VK_UP&&dir!=2){sdir=0;}
        if(w==VK_RIGHT&&dir!=3){sdir=1;}
        if(w==VK_DOWN&&dir!=0){sdir=2;}
        if(w==VK_LEFT&&dir!=1){sdir=3;}
        if(w=='R'||w=='r'){init(hw);}
        if(w=='P'||w=='p'){run=!run;}
        if(w==VK_ESCAPE)SendMessage(hw,WM_CLOSE,0,0);
        return 0;
    }
    return DefWindowProc(hw,msg,w,l);
}

int WINAPI WinMain(HINSTANCE h,HINSTANCE,LPSTR,int)
{
    ifstream fi("snake_hi.dat",ios::binary);fi.read((char*)&hi,sizeof(hi));
    loadQ();
    srand(time(0)+(int)GetTickCount());
    init();
    WNDCLASSA wc={};wc.style=CS_HREDRAW|CS_VREDRAW;wc.lpfnWndProc=WndProc;wc.hInstance=h;
    wc.hCursor=LoadCursorA(0,IDC_ARROW);wc.hbrBackground=0;
    wc.lpszClassName="SnakeWin";RegisterClassA(&wc);
    HWND hw=CreateWindowA("SnakeWin","贪吃蛇",WS_OVERLAPPEDWINDOW&~WS_MAXIMIZEBOX&~WS_THICKFRAME,
        CW_USEDEFAULT,CW_USEDEFAULT,W,H,0,0,h,0);
    ShowWindow(hw,SW_SHOW);
    SetTimer(hw,1,16,NULL);
    DWORD lt=GetTickCount();
    MSG msg;
    while(GetMessage(&msg,0,0,0))
    {
        if(msg.message==WM_TIMER)
        {
            DWORD now=GetTickCount();
            if(!menu&&!dead&&run){p+=(now-lt)/(float)ti;while(p>=1.0f){tick(hw);p-=1.0f;}if(p<0)p=0;}
            lt=now;InvalidateRect(hw,0,TRUE);
        }
        TranslateMessage(&msg);DispatchMessage(&msg);
    }
    KillTimer(hw,1);
    return 0;
}
