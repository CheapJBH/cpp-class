#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=2e5+5;
lnt n,m,a[N];
bool check(lnt x)
{
    lnt sum=0;
    for (int i=1;i<=n;i++)
    {
        sum+=min(a[i],x);
        if (sum>m) return 0;
    }
    return 1;
}
/*====================*/
/*====================*/
void Solve(void)
{
    cin>>n>>m;
    lnt sum_a=0,max_a=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum_a+=a[i];
        max_a=max(max_a,a[i]);
    }
    if (sum_a<=m)
    {
        cout<<"infinite"<<endl;
        return 0;
    }
    lnt lo=0,hi=max_a;
    while (lo<hi)
    {
        lnt mid=(lo+hi+1)>>1;
        if (check(mid)) lo=mid;
        else hi=mid-1;
    }
    cout<<lo<<endl;
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
