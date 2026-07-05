#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=1005;
lnt n,m,f[N];
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
    while (cin>>n)
    {
        if (n==0)
        {
            break;
        }
        cin>>m;
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
        lnt cnt=0;
        for (int i=1;i<=n;i++)
        {
            if (f[i]==i)
            {
                cnt++;
            }
        }
        cout<<cnt-1<<endl;
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
