#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int mod=1e9+7;
lnt n,a,b,c;
/*====================*/
void Solve(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    if (n<3)
    {
        cout<<0<<endl;
    }
    a=1;
    b=0;
    c=0;
    for (int i=3;i<=n;i++)
    {
        lnt d=(c+a)%mod;
        a=b;
        b=c;
        c=d;
    }
    cout<<c<<endl;
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
