#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=105;
const int MOD=998244353;

lnt n,a[N],dp[N][N],ans;
/*====================*/
/*====================*/
void Solve(void)
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (int k=1;k<=n;k++)
    {
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for (int i=1;i<=n;i++)
        {
            lnt rem=a[i]%k;
            for (int j=min(i,k);j>=1;j--)
            {
                for (int r=0;r<k;r++)
                {
                    dp[j][(r+rem)%k]=(dp[j][(r+rem)%k]+dp[j-1][r])%MOD;
                }
            }
        }
        ans=(ans+dp[k][0])%MOD;
    }
    ans=ans%MOD;
    cout<<ans<<endl;
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
