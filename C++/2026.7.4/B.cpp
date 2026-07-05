#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
void Solve(void)
{
    lnt x,y,l,r,a,b;
    cin>>x>>y>>l>>r>>a>>b;
    lnt overlap = max(0LL, min(b, r) - max(a, l));
    lnt total = b - a;
    cout<<(total - overlap) * y + overlap * x<<endl;
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
