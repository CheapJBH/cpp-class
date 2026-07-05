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
    map<lnt,vector<lnt>> mp;
    for (int i=1;i<=n;i++)
    {
        lnt x;
        cin>>x;
        mp[x].push_back(i);
    }
    lnt q;
    cin>>q;
    while (q--)
    {
        lnt l,r,x;
        cin>>l>>r>>x;
        auto it=mp.find(x);
        if (it==mp.end())
        {
            cout<<0<<endl;
            continue;
        }
        auto &v=it->second;
        lnt cnt=upper_bound(v.begin(),v.end(),r)-lower_bound(v.begin(),v.end(),l);
        cout<<cnt<<endl;
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
