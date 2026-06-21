#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+5;

int n,m;
vector<int> g[maxn],rg[maxn];
int d1[maxn],d2[maxn];

signed main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    memset(d1,-1,sizeof(d1));
    memset(d2,-1,sizeof(d2));
    queue<int> q;
    q.push(1);d1[1]=0;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int v:g[u])
        {
            if(d1[v]==-1)
            {
                d1[v]=d1[u]+1;
                q.push(v);
            }
        }
    }
    q.push(1);d2[1]=0;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int v:rg[u])
        {
            if(d2[v]==-1)
            {
                d2[v]=d2[u]+1;
                q.push(v);
            }
        }
    }
    int ans=1e18;
    for(int i=2;i<=n;i++)
    {
        if(d1[i]!=-1&&d2[i]!=-1)
        {
            ans=min(ans,d1[i]+d2[i]);
        }
    }
    if(ans==1e18) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}