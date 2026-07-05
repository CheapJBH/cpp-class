#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
/*====================*/
void Solve(void)
{
    lnt n,cnt=0;
    string s;
    cin>>s>>n;
    lnt N=s.size();
    reverse(s.begin(),s.end());
    for (int i=0;i<N;i++)
    {
        if (s[i]=='1') cnt+=(1LL<<i);
    }
    if (cnt>n)
    {
        cout<<-1;
        return 0;
    }
    if (cnt==n)
    {
        cout<<cnt;
        return 0;
    }
    for (int i=N-1;i>=0;i--)
    {
        if (s[i]=='?'&&(cnt+(1LL<<i))<=n) cnt+=(1LL<<i);
    }
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
