#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=5005;
const int maxa=5000;
const int mod=998244353;
lnt n,a[N],dp[maxa+5];
/*====================*/
/*====================*/
void Solve(void)
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dp[0]=1;
    lnt cnt=1,res=1;
    for (int i=1;i<=n;i++)
    {
        res=res*2%mod;
        for (int j=0;j<=a[i];j++)
        {
            cnt=(cnt+dp[j])%mod;
        }
        for (int j=maxa;j>=a[i];j--)
        {
            dp[j]=(dp[j]+dp[j-a[i]])%mod;
        }
    }
    cout<<(res-cnt+mod)%mod<<endl;
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
