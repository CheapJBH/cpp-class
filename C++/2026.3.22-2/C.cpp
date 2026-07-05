#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=1e6;
lnt f[N],s[N],n,w[N];
/*====================*/
/*====================*/
void Solve(void)
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>s[i];
    f[1]=1;
    for (int i=2;i<=n;i++)
    {
        if (w[i]>w[i-1]) f[i]=f[i-1]+1;
        else f[i]=1;
    }
    for (int i=2;i<=n;i++)
    {
        if (w[i]>w[i-1]) f[i]=f[i-1]+1;
        else f[i]=1;
    }
    s[n]=1;
    lnt res=0;
    for (int i=1;i<=n;i++) max(res,f[i]);
    for (int i=2;i<=n;i++) max(res,f[i-1]+1);
    for (int i=1;i<=n-1;i++) max(res,s[i+1]+1);
    for (int i=2;i<=n-1;i++) if (w[i+1]-w[i-1]>=2) max(res,f[i-1]+1+s[i+1]);
    cout<<res;
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
