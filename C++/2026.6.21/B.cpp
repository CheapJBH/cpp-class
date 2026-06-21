#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5005;
const int maxa=5000;
const int mod=998244353;
int n,a[maxn],dp[maxa+5];
signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dp[0]=1;
    int cnt=1,res=1;
    for(int i=1;i<=n;i++)
    {
        res=res*2%mod;
        for(int j=0;j<=a[i];j++)
        {
            cnt=(cnt+dp[j])%mod;
        }
        for(int j=maxa;j>=a[i];j--)
        {
            dp[j]=(dp[j]+dp[j-a[i]])%mod;
        }
    }
    cout<<(res-cnt+mod)%mod<<endl;
    return 0;
}
