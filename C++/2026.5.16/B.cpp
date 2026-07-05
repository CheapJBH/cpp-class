#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
lnt n,q;
const int N=1e9;
/*====================*/
/*====================*/
void Solve(void)
{
    lnt n,q;
    set<pair<lnt,lnt>> s;
    cin>>n>>q;
    for (int i=0;i<q;i++)
    {
        lnt l,r,a;
        cin>>a>>l>>r;
        if (a==1)
        {
            s.insert({l,r});
        }
        if (a==2)
        {
            s.erase({l,r});
        }
        if (a==3)
        {
            if (s.count({l,r})&&s.count({r,l})) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
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
