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
    lnt n,m;
    cin>>n>>m;
    vector<lnt> p(n);
    for (int i=0;i<n;i++) cin>>p[i];
    vector<lnt> dp(m+1);
    dp[0]=1;
    for (int i=0;i<n;i++)
    {
        for (int j=m;j>=p[i];j--)
        {
            dp[j]+=dp[j-p[i]];
        }
    }
    cout<<dp[m]<<endl;
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
