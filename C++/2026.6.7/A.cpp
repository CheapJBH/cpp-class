#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,a,b,c;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    if(n<3)
    {
        cout<<0<<endl;
        return 0;
    }
    a=1;
    b=0;
    c=0;
    for(int i=3;i<=n;i++)
    {
        int d=(c+a)%mod;
        a=b;
        b=c;
        c=d;
    }
    cout<<c<<endl;
    return 0;
}
    dp[0]=1;
    dp[1]=0;
    dp[2]=0;
    for(int i=3;i<=n;i++)
    {
        dp[i]=(dp[i-1]+dp[i-3])%mod;
    }
    cout<<dp[n]<<endl;
    return 0;
}

