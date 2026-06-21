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
    int n; cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) cin>>s[i][j];
    }
    int sx,sy,ex,ey;
    cin>>sx>>sy>>ex>>ey;
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
            if(nx>=1&&nx<=n&&ny>=1&&ny<=n&&dis[nx][ny]==-1&& s[nx][ny]=='0')
            {
                dis[nx][ny]=dis[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
    cout<<dis[ex][ey]<<endl;

    return 0;
}