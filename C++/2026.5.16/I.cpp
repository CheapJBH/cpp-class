#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int m,n;
    cin>>m>>n;
    vector<int> s(n),t(n);
    for(int i=0;i<n;i++)
    {
        cin>>s[i]>>t[i];
    }
    vector<int> dp(m+1);
    for(int i=0;i<n;i++)
    {
        for(int j=t[i];j<=m;j++)
        {
            dp[j]=max(dp[j],dp[j-t[i]]+s[i]);
        }
    }
    int ans=0;
    for(int j=0;j<=m;j++) ans=max(ans,dp[j]);
    cout<<ans<<endl;
    return 0;
}
