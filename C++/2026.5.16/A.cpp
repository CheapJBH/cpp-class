#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=2e5+5;
lnt n,m,a[N],p1[N],p2[N];
/*====================*/
/*====================*/
void Solve(void)
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        p1[i]=p1[i-1]+a[i];
        p2[i]=p2[i-1]+(i*a[i]);
    }
    lnt res=-1e18;
    for (int i=m;i<=n;i++)
    {
        lnt sum=(p2[i]-p2[i-m])-(i-m)*(p1[i]-p1[i-m]);
        res=max(sum,res);
    }
    cout<<res<<endl;
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
