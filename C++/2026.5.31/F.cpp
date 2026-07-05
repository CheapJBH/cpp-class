#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=100005;
lnt n,m,f[N];
struct edge
{
    lnt u,v,c;
}e[N];
bool cmp(edge a,edge b)
{
    return a.c<b.c;
}
lnt ffind(lnt x)
{
    if (f[x]==x)
    {
        return x;
    }
    return f[x]=ffind(f[x]);
}
/*====================*/
/*====================*/
void Solve(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        f[i]=i;
    }
    for (int i=1;i<=m;i++)
    {
        cin>>e[i].u>>e[i].v>>e[i].c;
    }
    sort(e+1,e+m+1,cmp);
    lnt cnt=0,ans=0;
    for (int i=1;i<=m;i++)
    {
        lnt fx=ffind(e[i].u),fy=ffind(e[i].v);
        if (fx!=fy)
        {
            f[fx]=fy;
            cnt++;
            ans=e[i].c;
            if (cnt==n-1)
            {
                break;
            }
        }
    }
    cout<<n-1<<' '<<ans<<endl;
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
