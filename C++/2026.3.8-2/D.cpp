#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=1e3+5;
lnt n,m;
lnt p[N],f[N][N],a[N][N];
/*====================*/
/*====================*/
void Solve(void)
{
    cin>>n>>m;
    f[1][1]=1;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (i==1&&j==1) continue;
            if (i%2==0&&j%2==0)
            {
                f[i][j]=0;
            }
            else
            {
                f[i][j]=f[i-1][j]+f[i][j-1];
            }
        }
    }
    cout<<f[n][m];
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
