#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=1e3+5;
lnt n;
lnt x1,y_1,x2,y2;
char grid[N][N];
lnt dis[N][N];
struct node
{
    lnt xx;
    lnt yy;
};

void bfs(lnt sx,lnt sy)
{
    static const int dx[]={0,0,-1,1};
    static const int dy[]={1,-1,0,0};
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            dis[i][j] = -1;

    queue<node> q;
    q.push({sx,sy});
    dis[sx][sy]=0;
    while (!q.empty())
    {
        node t=q.front(); q.pop();
        lnt tx=t.xx,ty=t.yy;
        for (int i=0;i<4;i++)
        {
            lnt nx=tx+dx[i];
            lnt ny=ty+dy[i];
            if (nx>=1 && nx<=n && ny>=1 && ny<=n && dis[nx][ny]==-1 && grid[nx][ny]!=grid[tx][ty])
            {
                dis[nx][ny] = dis[tx][ty] + 1;
                q.push({nx,ny});
            }
        }
    }
}
/*====================*/
/*====================*/
void Solve(void)
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            cin>>grid[i][j];
            if (grid[i][j]=='A') x1=i,y_1=j;
            else if (grid[i][j]=='B') x2=i,y2=j;
        }
    }
    bfs(x1,y_1);
    cout<<dis[x2][y2]<<"\n";
}
/*====================*/
int main()
{
#ifndef ONLINE_JUDGE
    freopen("IN.txt", "r+", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; //cin >> T;
    while (T--)Solve();
    return 0;
}
