#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=1e6+5;
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
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        f[i]=i;
    }
    while (m--)
    {
        lnt op,x,y;
        cin>>op>>x>>y;
        lnt fx=ffind(x),fy=ffind(y);
        if (op==1)
        {
            f[fx]=fy;
        }
        else
        {
            if (fx==fy)
            {
                cout<<'Y'<<endl;
            }
            else
            {
                cout<<'N'<<endl;
            }
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
