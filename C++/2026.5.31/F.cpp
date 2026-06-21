#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=100005;
int n,m,f[maxn];
struct edge
{
    int u,v,c;
}e[maxn];
bool cmp(edge a,edge b)
{
    return a.c<b.c;
}
int ffind(int x)
{
    if(f[x]==x)
    {
        return x;
    }
    return f[x]=ffind(f[x]);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        f[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>e[i].u>>e[i].v>>e[i].c;
    }
    sort(e+1,e+m+1,cmp);
    int cnt=0,ans=0;
    for(int i=1;i<=m;i++)
    {
        int fx=ffind(e[i].u),fy=ffind(e[i].v);
        if(fx!=fy)
        {
            f[fx]=fy;
            cnt++;
            ans=e[i].c;
            if(cnt==n-1)
            {
                break;
            }
        }
    }
    cout<<n-1<<' '<<ans<<endl;
    return 0;
}
