#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=4e3+5;
lnt n,t,m,f[N];
lnt a[N],b[N];
/*====================*/
/*====================*/
void Solve(void)
{
    cin>>t>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=t;j>=a[i];j--)
        {
            if (j-a[i]>=0) f[j]=max(f[j],f[j-a[i]]+b[i]);
        }
    }
    cout<<f[t];
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
