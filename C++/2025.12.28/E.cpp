#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+5;

int dis[maxn];

signed main()
{
    int n;
    cin>>n;
    memset(dis,-1,sizeof(dis));
    queue<int> q;
    q.push(1);
    dis[1]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(u-1>=1&&u-1<=n&&dis[u-1]==-1) dis[u-1]=dis[u]+1,q.push(u-1);
        if(u+1>=1&&u+1<=n&&dis[u+1]==-1) dis[u+1]=dis[u]+1,q.push(u+1);
        if(2*u>=1&&2*u<=n&&dis[2*u]==-1) dis[2*u]=dis[u]+1,q.push(2*u);
    }
    
    cout<<dis[n];
    return 0;
}