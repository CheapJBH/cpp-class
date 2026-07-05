#include<bits/stdc++.h>
using namespace std;
/*====================*/
const int N=1e3+5;

char s[N][N];
lnt dis[N][N];

struct node
{
    lnt x,y;
};
lnt dx[]={-1,1,0,0};
lnt dy[]={0,0,1,-1};
/*====================*/
/*====================*/`nvoid Solve(void)
{
    lnt n; cin>>n;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++) cin>>s[i][j];
    }
    lnt sx,sy,ex,ey;
    cin>>sx>>sy>>ex>>ey;
    memset(dis,-1,sizeof(dis));
    queue<node> q;
    q.push({sx,sy});
    dis[sx][sy]=0;
    while (!q.empty())
    {
        node u=q.front();
        q.pop();
        lnt x=u.x,y=u.y;
        for (int i=0;i<4;i++)
        {
            lnt nx=x+dx[i],ny=y+dy[i];
            if (nx>=1&&nx<=n&&ny>=1&&ny<=n&&dis[nx][ny]==-1&& s[nx][ny]=='0')
            {
                dis[nx][ny]=dis[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
    cout<<dis[ex][ey]<<endl;
}
/*====================*/
/*====================*/
void Solve(void)
{
#ifndef ONLINE_JUDGE
    freopen("IN.txt", "r+", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; //cin >> T;
    while (T--)Solve();
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
