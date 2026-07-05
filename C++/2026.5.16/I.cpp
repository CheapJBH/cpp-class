#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
/*====================*/
void Solve(void)
{
    lnt m,n;
    cin>>m>>n;
    vector<lnt> s(n),t(n);
    for (int i=0;i<n;i++)
    {
        cin>>s[i]>>t[i];
    }
    vector<lnt> dp(m+1);
    for (int i=0;i<n;i++)
    {
        for (int j=t[i];j<=m;j++)
        {
            dp[j]=max(dp[j],dp[j-t[i]]+s[i]);
        }
    }
    lnt ans=0;
    for (int j=0;j<=m;j++) ans=max(ans,dp[j]);
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
