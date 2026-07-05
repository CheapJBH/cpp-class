#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=1e3+5;
lnt n,r[N][N],f[N];
/*====================*/
/*====================*/
void Solve(void)
{
    cin>>n;
    for (int i=1;i<=n-1;i++)
    {
        for (int j=i+1;j<=n;j++)
        {
            cin>>r[i][j];
        }
    }
    for (int i=1;i<=n;i++) f[i]=1e6;
    f[1]=0;
    for (int i=2;i<=n;i++)
    {
        for (int j=1;j<=i-1;j++) f[i]=min(f[i],f[j]+r[j][i]);
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
