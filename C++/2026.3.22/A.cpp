#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=2e3+5;
lnt m,n,a[N][N],f[N][N];
/*====================*/
/*====================*/
void Solve(void)
{
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        } 
    }
    for (int j=1;j<=n;j++)
    {
        for (int i=1;i<=m;i++)
        {
            if (i==1) f[i][j]=min(f[i][j-1],f[m][j-1])+a[i][j];
            else f[i][j]=min(f[i][j-1],f[i-1][j-1])+a[i][j];
        }
    }
    lnt ans=1e9;
    for (int i=1;i<=m;i++)
    {
        ans=min(ans,f[i][n]);
        
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
