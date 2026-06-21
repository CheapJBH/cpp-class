#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e3+5;
int n;
int x1,y_1,x2,y2;
char grid[maxn][maxn];
int dis[maxn][maxn];
struct node
{
    int xx;
    int yy;
};


void bfs(int sx,int sy)
{
    static const int dx[]={0,0,-1,1};
    static const int dy[]={1,-1,0,0};
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j] = -1;

    queue<node> q;
    q.push({sx,sy});
    dis[sx][sy]=0;
    while(!q.empty())
    {
        node t=q.front(); q.pop();
        int tx=t.xx,ty=t.yy;
        for(int i=0;i<4;i++)
        {
            int nx=tx+dx[i];
            int ny=ty+dy[i];
            if(nx>=1 && nx<=n && ny>=1 && ny<=n && dis[nx][ny]==-1 && grid[nx][ny]!=grid[tx][ty])
            {
                dis[nx][ny] = dis[tx][ty] + 1;
                q.push({nx,ny});
            }
        }
    }
}

signed main()
{   
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>grid[i][j];
            if(grid[i][j]=='A') x1=i,y_1=j;
            else if(grid[i][j]=='B') x2=i,y2=j;
        }
    }
    bfs(x1,y_1);
    cout<<dis[x2][y2]<<"\n";
    return 0;
}