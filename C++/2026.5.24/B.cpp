#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=105;
const int MOD=998244353;

int n,a[maxn],dp[maxn][maxn],ans;

signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int k=1;k<=n;k++)
    {
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            int rem=a[i]%k;
            for(int j=min(i,k);j>=1;j--)
            {
                for(int r=0;r<k;r++)
                {
                    dp[j][(r+rem)%k]=(dp[j][(r+rem)%k]+dp[j-1][r])%MOD;
                }
            }
        }
        ans=(ans+dp[k][0])%MOD;
    }
    ans=ans%MOD;
    cout<<ans<<endl;
    return 0;
}
