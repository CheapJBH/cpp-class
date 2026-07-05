#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=5e5+5;
long long n,m,f[N];
long long a[N],b[N];
/*====================*/
/*====================*/
void Solve(void)
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    for (int i=1;i<=N;i++)
    {
        f[i]=1e9;
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            f[j]=min(f[j],f[max((long long)(0),j-a[i])]+b[i]);
        }
    }
    cout<<f[m];
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
