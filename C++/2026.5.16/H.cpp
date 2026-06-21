#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=1e18;

void solve()
{
    int n,p,q;
    cin>>n>>p>>q;
    vector<int> a(n),c(n);
    int sum_a=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>c[i];
        sum_a+=a[i];
    }
    if(sum_a<p)
    {
        cout<<-1<<endl;
        return;
    }
    if(p<=q)
    {
        vector<int> dp(p+1,INF);
        dp[0]=0;
        for(int i=0;i<n;i++)
        {
            for(int s=p;s>=0;s--)
            {
                if(dp[s]!=INF)
                {
                    int ns=min(p,s+a[i]);
                    dp[ns]=min(dp[ns],dp[s]+c[i]);
                }
            }
        }
        if(dp[p]<=q) cout<<dp[p]<<endl;
        else cout<<-1<<endl;
    }
    else
    {
        vector<int> dp(q+1,-INF);
        dp[0]=0;
        for(int i=0;i<n;i++)
        {
            for(int cost=q;cost>=c[i];cost--)
            {
                if(dp[cost-c[i]]!=-INF)
                {
                    dp[cost]=max(dp[cost],dp[cost-c[i]]+a[i]);
                }
            }
        }
        int ans=-1;
        for(int cost=0;cost<=q;cost++)
        {
            if(dp[cost]>=p)
            {
                ans=cost;
                break;
            }
        }
        cout<<ans<<endl;
    }
}

signed main()
{
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
