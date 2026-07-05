#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=5e5+5;
const int mod=998244353;
lnt n,f[N];
/*====================*/
/*====================*/
void Solve(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    f[0]=1;
    f[1]=0;
    f[2]=0;
    for (int i=3;i<=n;i++)
    {
        f[i]=(f[i-1]+f[i-3])%mod;
    }
    cout<<f[n]<<endl;
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
