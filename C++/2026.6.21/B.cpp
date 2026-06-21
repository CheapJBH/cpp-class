#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5005;
const int maxsum=5005;
const int mod=998244353;
int n,a[maxn],dp[maxsum];
signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dp[0]=1;
    int ans=0,cur=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=cur;j>a[i];j--)
        {
            ans=(ans+dp[j])%mod;
        }
        cur+=a[i];
        if(cur>=maxsum) cur=maxsum-1;
        for(int j=cur;j>=a[i];j--)
        {
            dp[j]=(dp[j]+dp[j-a[i]])%mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}
