#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e3+5;

int dis[maxn][maxn];

struct node
{
    int x,y;
};

int dx[]={1,2,2,1,-1,-2,-2,-1};
int dy[]={2,1,-1,-2,-2,-1,1,2};

signed main()
{
    int h,w,sx,sy;
    cin>>h>>w>>sx>>sy;
    memset(dis,-1,sizeof(dis));
    queue<node> q;
    q.push({sx,sy});
    dis[sx][sy]=0;
    while(!q.empty())
    {
        node u=q.front();
        q.pop();
        int x=u.x,y=u.y;
        for(int i=0;i<8;i++)
        {
            int nx=x+dx[i],ny=y+dy[i];
            if(nx>=1&&nx<=h&&ny>=1&&ny<=w&&dis[nx][ny]==-1)
            {
                dis[nx][ny]=dis[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}