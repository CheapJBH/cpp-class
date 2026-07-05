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
    lnt n;
    cin>>n;
    map<lnt,lnt> cnt;
    lnt sum=0;
    for (int i=1;i<=n;i++)
    {
        lnt x;
        cin>>x;
        cnt[x]++;
        sum+=x;
    }
    lnt q;
    cin>>q;
    while (q--)
    {
        lnt x,y;
        cin>>x>>y;
        if (x==y)
        {
            cout<<sum<<endl;
            continue;
        }
        auto it=cnt.find(x);
        if (it==cnt.end())
        {
            cout<<sum<<endl;
            continue;
        }
        lnt cx=it->second;
        sum+=cx*(y-x);
        cnt[y]+=cx;
        cnt.erase(it);
        cout<<sum<<endl;
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
