#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n,m;
    cin>>n>>m;
    vector<int> p(n);
    for(int i=0;i<n;i++) cin>>p[i];
    vector<int> dp(m+1);
    dp[0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=m;j>=p[i];j--)
        {
            dp[j]+=dp[j-p[i]];
        }
    }
    cout<<dp[m]<<endl;
    return 0;
}
