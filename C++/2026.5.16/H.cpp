#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int INF=1e18;

/*====================*/
void solve()
{
    lnt n,p,q;
    cin>>n>>p>>q;
    vector<lnt> a(n),c(n);
    lnt sum_a=0;
    for (int i=0;i<n;i++)
    {
        cin>>a[i]>>c[i];
        sum_a+=a[i];
    }
    if (sum_a<p)
    {
        cout<<-1<<endl;
        return;
    }
    if (p<=q)
    {
        vector<lnt> dp(p+1,INF);
        dp[0]=0;
        for (int i=0;i<n;i++)
        {
            for (int s=p;s>=0;s--)
            {
                if (dp[s]!=INF)
                {
                    lnt ns=min(p,s+a[i]);
                    dp[ns]=min(dp[ns],dp[s]+c[i]);
                }
            }
        }
        if (dp[p]<=q) cout<<dp[p]<<endl;
        else cout<<-1<<endl;
    }
    else
    {
        vector<lnt> dp(q+1,-INF);
        dp[0]=0;
        for (int i=0;i<n;i++)
        {
            for (int cost=q;cost>=c[i];cost--)
            {
                if (dp[cost-c[i]]!=-INF)
                {
                    dp[cost]=max(dp[cost],dp[cost-c[i]]+a[i]);
                }
            }
        }
        lnt ans=-1;
        for (int cost=0;cost<=q;cost++)
        {
            if (dp[cost]>=p)
            {
                ans=cost;
                break;
            }
        }
        cout<<ans<<endl;
    }
}
/*====================*/
/*====================*/
void Solve(void)
{
    lnt t;
    cin>>t;
    while (t--) solve();
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
