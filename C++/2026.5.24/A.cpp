#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=1e2+5;
lnt n,k,d,a[N],f[N][N][N];
/*====================*/
/*====================*/
void Solve(void)
{
    cin>>n>>k>>d;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=0;i<=100;i++)
    {
        for (int j=0;j<=100;j++)
        {
            for (int k=0;k<=100;k++)
            {
                f[i][j][k]=-1e18;  
            }
        }
    }
    f[0][0][0]=0;
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<=k;j++)
        {
            for (int g=0;g<=d;g++)
            {
                if (j==0)
                {
                    f[i][j][g]=f[i-1][j][g];
                }
                else f[i][j][g]=max(f[i-1][j][g],f[i-1][j-1][(g-a[i]%d+d)%d]+a[i]);
            }
        }
    }
    if (f[n][k][0]<0) cout<<-1;
    else cout<<f[n][k][0];
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
