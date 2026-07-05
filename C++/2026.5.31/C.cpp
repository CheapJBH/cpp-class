#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=1e6+5;
lnt n,m,q,f[N];
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
    cin>>n>>m>>q;
    for (int i=1;i<=n;i++)
    {
        f[i]=i;
    }
    for (int i=1;i<=m;i++)
    {
        lnt x,y;
        cin>>x>>y;
        lnt fx=ffind(x),fy=ffind(y);
        if (fx!=fy)
        {
            f[fx]=fy;
        }
    }
    for (int i=1;i<=q;i++)
    {
        lnt x,y;
        cin>>x>>y;
        lnt fx=ffind(x),fy=ffind(y);
        if (fx==fy)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
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
