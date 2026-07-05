#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=1e5+5;
lnt n;
lnt a[N],ans;
priority_queue<lnt,vector<lnt>,greater<lnt>>q;
/*====================*/
/*====================*/
void Solve(void)
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        lnt m;
        cin>>m;
        q.push(m);
    }
    while (q.size()>=2)
    {
        lnt b=0;
        b+=q.top();
        q.pop();
        b+=q.top();
        q.pop();
        q.push(b);
        ans+=b;
    }
    cout<<ans;
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
