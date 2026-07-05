#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=4e5+5;
lnt n,v,f[N];
lnt a[N],b[N];
/*====================*/
/*====================*/
void Solve(void)
{
    cin>>v>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=v;j>=a[i];j--)
        {
            if (j-a[i]>=0) f[j]=max(f[j],f[j-a[i]]+a[i]);
        }
    }
    cout<<v-f[v];
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
