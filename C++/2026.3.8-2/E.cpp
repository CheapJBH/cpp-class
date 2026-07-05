#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=1e3+5;
lnt n;
lnt p[N][N],f[N][N],a[N][N];
/*====================*/
/*====================*/
void Solve(void)
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=i;j++)
        {
            cin>>a[i][j];
        }
    }
    f[1][1]=a[1][1];
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=i;j++)
        {
            if (i==1&&j==1) continue;
            f[i][j]=f[i-1][j-1]+f[i-1][j];
        }
    }
    lnt ans=-100;
    for (int i=1;i<=n;i++)
    {
        ans=max(ans,f[n][i]);
    }
    cout<<ans;
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
