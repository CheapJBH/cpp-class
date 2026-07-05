#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=5e5+5;
/*====================*/
/*====================*/
void Solve(void)
{
    lnt n,m,res=0;
    cin>>n>>m;
    queue<lnt> q;
    map<lnt,bool> mp;
    while (m--)
    {
        lnt x;
        cin>>x;
        if (mp[x]==true) continue;
        q.push(x),mp[x]=true,res++;
        if (q.size()>n)
        {
            lnt t=q.front();
            mp[t]=false,q.pop();
        }
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
