#include<bits/stdc++.h>
#undef UNICODE
#undef _UNICODE
#include<windows.h>
using namespace std;
const int maxn=10,N=5,CELL=90;
int money=100,day;
int g[maxn][maxn],t[maxn][maxn];
int sx,sy,sel;
string key="farm";

struct seed
{
    string n;
    int c,g,p; COLORREF col;
};
seed a[4]={
    {"",0,0,0,0},
    {"小麦",10,3,30,RGB(255,200,50)},
    {"胡萝卜",30,5,80,RGB(255,120,50)},
    {"西瓜",50,7,150,RGB(60,180,60)}
};

string xorenc(string s,string k)
{
    string r;
    for(int i=0;i<s.size();i++) r+=s[i]^k[i%k.size()];
    return r;
}

string tohex(string s)
{
    string r; char t[5];
    for(int i=0;i<s.size();i++){sprintf(t,"%02x",(unsigned char)s[i]);r+=t;}
    return r;
}

string fromhex(string s)
{
    string r;
    for(int i=0;i<s.size();i+=2){int x;sscanf(s.substr(i,2).c_str(),"%02x",&x);r+=char(x);}
    return r;
}

string save()
{
    string s=to_string(day)+","+to_string(money);
    for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)s+=","+to_string(g[i][j])+","+to_string(t[i][j]);
    return tohex(xorenc(s,key));
}

void load(string s)
{
    s=xorenc(fromhex(s),key);
    stringstream ss(s); string tmp;
    getline(ss,tmp,','); day=stoll(tmp);
    getline(ss,tmp,','); money=stoll(tmp);
    for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)
    {getline(ss,tmp,',');g[i][j]=stoll(tmp);getline(ss,tmp,',');t[i][j]=stoll(tmp);}
}

void draw(HDC h)
{
    RECT rc; GetClientRect(WindowFromDC(h),&rc);
    int W=rc.right,H=rc.bottom,lx=10,ly=30;
    HBRUSH hb=CreateSolidBrush(RGB(20,20,30));
    FillRect(h,&rc,hb); DeleteObject(hb);

    // grid
    HPEN hp=CreatePen(PS_SOLID,2,RGB(60,60,80));
    SelectObject(h,hp);
    for(int i=0;i<=N;i++)
    {
        MoveToEx(h,lx+i*CELL,ly,NULL); LineTo(h,lx+i*CELL,ly+N*CELL);
        MoveToEx(h,lx,ly+i*CELL,NULL); LineTo(h,lx+N*CELL,ly+i*CELL);
    }

    for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)
    {
        int x=lx+(j-1)*CELL+2,y=ly+(i-1)*CELL+2,w=CELL-4,hc=CELL-4;
        if(g[i][j]==0){HPEN hp2=CreatePen(PS_SOLID,1,RGB(60,60,80));SelectObject(h,hp2);DeleteObject(hp2);}
        else
        {
            COLORREF col=a[g[i][j]].col;
            HBRUSH hb2=CreateSolidBrush(col);
            HPEN hp2=CreatePen(PS_SOLID,2,col);
            SelectObject(h,hp2); SelectObject(h,hb2);
            RoundRect(h,x,y,x+w,y+hc,12,12);
            DeleteObject(hb2); DeleteObject(hp2);
        }
        if(sel==i*10+j){HPEN hp3=CreatePen(PS_SOLID,3,RGB(255,255,100));SelectObject(h,hp3);SelectObject(h,GetStockObject(NULL_BRUSH));RoundRect(h,x-2,y-2,x+w+2,y+hc+2,14,14);DeleteObject(hp3);}
    }

    // texts
    SetBkMode(h,TRANSPARENT);
    HFONT hf=CreateFont(22,0,0,0,0,0,0,0,0,0,0,0,0,"Segoe UI");
    SelectObject(h,hf);

    int xx=lx+N*CELL+20,yy=ly;
    SetTextColor(h,RGB(200,200,200));
    string d="Day: "+to_string(day); TextOutA(h,xx,yy,d.c_str(),d.size());
    yy+=30;
    string m="Gold: "+to_string(money); TextOutA(h,xx,yy,m.c_str(),m.size());
    yy+=50;

    if(sel)
    {
        int i=sel/10,j=sel%10;
        string si="["+to_string(i)+","+to_string(j)+"]"; TextOutA(h,xx,yy,si.c_str(),si.size()); yy+=30;
        if(g[i][j]>0)
        {
            SetTextColor(h,a[g[i][j]].col);
            TextOutA(h,xx,yy,a[g[i][j]].n.c_str(),a[g[i][j]].n.size()); yy+=25;
            SetTextColor(h,RGB(200,200,200));
            string sp=to_string(t[i][j])+"/"+to_string(a[g[i][j]].g); TextOutA(h,xx,yy,sp.c_str(),sp.size()); yy+=25;
            if(t[i][j]>=a[g[i][j]].g){SetTextColor(h,RGB(100,255,100));TextOutA(h,xx,yy,"READY!",6);yy+=30;}
            else{SetTextColor(h,RGB(255,200,100));TextOutA(h,xx,yy,"GROWING",7);yy+=30;}
        }
        else TextOutA(h,xx,yy,"EMPTY",5);
    }

    yy=H-180;
    SetTextColor(h,RGB(150,150,150));
    TextOutA(h,xx,yy,"[1] Plant",8); yy+=22;
    TextOutA(h,xx,yy,"[2] Water",8); yy+=22;
    TextOutA(h,xx,yy,"[3] Harvest",10); yy+=22;
    TextOutA(h,xx,yy,"[4] Shop",7); yy+=22;
    TextOutA(h,xx,yy,"[5] Next Day",11); yy+=22;
    TextOutA(h,xx,yy,"[6] Save / [7] Load",19); yy+=22;
    TextOutA(h,xx,yy,"[8] New Game",11);

    DeleteObject(hf);
}

LRESULT CALLBACK WndProc(HWND hw,UINT msg,WPARAM w,LPARAM l)
{
    if(msg==WM_DESTROY){PostQuitMessage(0);return 0;}
    if(msg==WM_PAINT)
    {
        PAINTSTRUCT ps; HDC hdc=BeginPaint(hw,&ps);
        draw(hdc);
        EndPaint(hw,&ps);
        return 0;
    }
    if(msg==WM_LBUTTONDOWN)
    {
        int mx=LOWORD(l),my=HIWORD(l);
        int cx=(mx-10)/CELL+1,cy=(my-30)/CELL+1;
        if(cx>=1&&cx<=N&&cy>=1&&cy<=N) sel=cy*10+cx;
        InvalidateRect(hw,NULL,TRUE);
        return 0;
    }
    if(msg==WM_KEYDOWN)
    {
        if(sel)
        {
            int i=sel/10,j=sel%10;
            if(w=='1')
            {
                if(g[i][j]==0)
                {
                    cout<<"Seed(1w 2c 3m): ";int s;cin>>s;
                    if(s>=1&&s<=3&&money>=a[s].c){g[i][j]=s;t[i][j]=0;money-=a[s].c;}
                }
            }
            if(w=='2'){if(g[i][j]>0)t[i][j]=min(t[i][j]+1,a[g[i][j]].g);}
            if(w=='3'){if(g[i][j]>0&&t[i][j]>=a[g[i][j]].g){money+=a[g[i][j]].p;g[i][j]=0;t[i][j]=0;}}
            if(w=='4')
            {
                cout<<"1w 2c 3m: ";int s;cin>>s;
                if(s>=1&&s<=3&&money>=a[s].c)
                {
                    for(int ii=1;ii<=N;ii++)for(int jj=1;jj<=N;jj++)if(g[ii][jj]==0){g[ii][jj]=s;t[ii][jj]=0;money-=a[s].c;goto done1;}
                    done1:;
                }
            }
            if(w=='5')
            {
                day++;
                for(int ii=1;ii<=N;ii++)for(int jj=1;jj<=N;jj++)if(g[ii][jj]>0&&t[ii][jj]<a[g[ii][jj]].g)t[ii][jj]++;
            }
            if(w=='6')
            {
                string code=save();
                ofstream f("farm_save.txt");f<<code;f.close();
                MessageBoxA(hw,(code+"\n(saved to farm_save.txt)").c_str(),"Save Code",0);
            }
            if(w=='7')
            {
                ifstream f("farm_save.txt");string code;f>>code;f.close();
                if(!code.empty())try{load(code);}catch(...){}
            }
            if(w=='8')
            {
                memset(g,0,sizeof(g));memset(t,0,sizeof(t));
                day=0;money=100;sel=0;
            }
        }
        InvalidateRect(hw,NULL,TRUE);
        return 0;
    }
    return DefWindowProc(hw,msg,w,l);
}

int WINAPI WinMain(HINSTANCE h,HINSTANCE,LPSTR,int)
{
    WNDCLASSA wc={}; wc.style=CS_HREDRAW|CS_VREDRAW; wc.lpfnWndProc=WndProc; wc.hInstance=h;
    wc.hCursor=LoadCursor(0,IDC_ARROW); wc.hbrBackground=(HBRUSH)COLOR_WINDOW;
    wc.lpszClassName="FarmWin"; RegisterClassA(&wc);
    HWND hw=CreateWindowA("FarmWin","Farm Game",WS_OVERLAPPEDWINDOW&~WS_MAXIMIZEBOX&~WS_THICKFRAME,
        CW_USEDEFAULT,CW_USEDEFAULT,N*CELL+220,480,0,0,h,0);
    ShowWindow(hw,SW_SHOW);
    MSG msg; while(GetMessage(&msg,0,0,0)){TranslateMessage(&msg);DispatchMessage(&msg);}
    return 0;
}
