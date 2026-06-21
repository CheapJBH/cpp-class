#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e3+5;

char s[maxn][maxn];
int dis[maxn][maxn];

struct node
{
    int x,y;
};

int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};

signed main()
{
    int h,w;
    cin>>h>>w;
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++) cin>>s[i][j];
    }
    int sx=1,sy=1,ex=h,ey=w;
    memset(dis,-1,sizeof(dis));
    queue<node> q;
    q.push({sx,sy});
    dis[sx][sy]=0;
    while(!q.empty())
    {
        node u=q.front();
        q.pop();
        int x=u.x,y=u.y;
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i],ny=y+dy[i];
            char xxx=s[x][y];
            if(nx>=1&&nx<=h&&ny>=1&&ny<=w&&dis[nx][ny]==-1&& s[nx][ny]!=xxx)
            {
                dis[nx][ny]=dis[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
    cout<<dis[ex][ey]<<endl;

    return 0;
}