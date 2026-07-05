#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=2e3+5;
lnt n,t,a[N],f[N],p[N];
/*====================*/
/*====================*/
void Solve(void)
{
    cin>>n>>t;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        p[i]=p[i-1]+a[i];

    }
    for (int i=1;i<=n;i++)
    {
        lnt ans=n*n*a[i]+f[i-1];
        for (int j=1;j<i;j++)
        {
            if (a[i]+a[j]>t) continue;
            ans=min(ans,(a[i]+a[j])*(p[i]-p[j-1])+f[j-1]);
        }
    }
    cout<<f[n];
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
