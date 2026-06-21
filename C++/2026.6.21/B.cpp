#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5005;
const int maxsum=1000005;
const int mod=998244353;
int n,a[maxn],dp[maxsum],pre[maxsum];
signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dp[0]=pre[0]=1;
    int ans=0,cur=0,total=1;
    for(int i=1;i<=n;i++)
    {
        int le=a[i]<=cur?pre[a[i]]:total;
        ans=(ans+total-le+mod)%mod;
        cur+=a[i];
        if(cur>=maxsum) cur=maxsum-1;
        for(int j=cur;j>=a[i];j--)
        {
            dp[j]=(dp[j]+dp[j-a[i]])%mod;
        }
        for(int j=a[i];j<=cur;j++)
        {
            pre[j]=(pre[j-1]+dp[j])%mod;
        }
        total=total*2%mod;
    }
    cout<<ans<<endl;
    return 0;
}
