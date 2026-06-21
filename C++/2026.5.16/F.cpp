#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2005;

int n,m;
vector<int> g[maxn];
int vis[maxn];

signed main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }
    int total=0;
    for(int s=1;s<=n;s++)
    {
        int cnt=0;
        queue<int> q;
        q.push(s);
        vis[s]=s;
        while(!q.empty())
        {
            int u=q.front();q.pop();
            for(int v:g[u])
            {
                if(vis[v]!=s)
                {
                    vis[v]=s;
                    q.push(v);
                    cnt++;
                }
            }
        }
        total+=cnt;
    }
    cout<<total-m<<endl;
    return 0;
}
