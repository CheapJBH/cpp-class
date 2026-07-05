#include<bits/stdc++.h>
using namespace std;
/*====================*/
const int N=1e3+5;

lnt dis[N][N];

struct node
{
    lnt x,y;
};

lnt dx[]={1,2,2,1,-1,-2,-2,-1};
lnt dy[]={2,1,-1,-2,-2,-1,1,2};
/*====================*/
/*====================*/`nvoid Solve(void)
{
    lnt h,w,sx,sy;
    cin>>h>>w>>sx>>sy;
    memset(dis,-1,sizeof(dis));
    queue<node> q;
    q.push({sx,sy});
    dis[sx][sy]=0;
    while (!q.empty())
    {
        node u=q.front();
        q.pop();
        lnt x=u.x,y=u.y;
        for (int i=0;i<8;i++)
        {
            lnt nx=x+dx[i],ny=y+dy[i];
            if (nx>=1&&nx<=h&&ny>=1&&ny<=w&&dis[nx][ny]==-1)
            {
                dis[nx][ny]=dis[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
    for (int i=1;i<=h;i++)
    {
        for (int j=1;j<=w;j++)
        {
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
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
