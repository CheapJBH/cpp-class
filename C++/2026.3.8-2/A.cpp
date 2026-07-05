#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=1e4+5;

lnt f[N],a[N];
/*====================*/
/*====================*/
void Solve(void)
{
    lnt n;
    cin>>n;
    f[0]=1;
    f[1]=1;
    f[2]=2;
    for (int i=3;i<=n;i++)
    {
        f[i]=f[i-1]+f[i-2]+f[i-3];
    }
    cout<<f[n];
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
