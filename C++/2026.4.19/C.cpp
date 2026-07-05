#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=1e3+5;
lnt n,t,v,f[N][N];
lnt a[N],b[N];
/*====================*/
/*====================*/
void Solve(void)
{
    cin>>n>>v>>t;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=v;j>=a[i];j--)
        {
            for (int k=t;k>=b[i];k--)
            {
                f[j][k]=max(f[j][k],f[j-a[i]][k-b[i]]+1);
            }
        }
    }
    cout<<f[v][t];
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
