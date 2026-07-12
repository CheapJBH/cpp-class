#include<bits/stdc++.h>
using namespace std;
/*====================*/
const int N=1e6+5;
/*====================*/
using lnt = long long;
/*====================*/
lnt dis[N];
/*====================*/
/*====================*/
void Solve(void)
{
    lnt n;
    cin>>n;
    memset(dis,-1,sizeof(dis));
    queue<lnt> q;
    q.push(1);
    dis[1]=0;
    while (!q.empty())
    {
        lnt u=q.front();
        q.pop();
        if (u-1>=1&&u-1<=n&&dis[u-1]==-1) dis[u-1]=dis[u]+1,q.push(u-1);
        if (u+1>=1&&u+1<=n&&dis[u+1]==-1) dis[u+1]=dis[u]+1,q.push(u+1);
        if (2*u>=1&&2*u<=n&&dis[2*u]==-1) dis[2*u]=dis[u]+1,q.push(2*u);
    }
    
    cout<<dis[n];
}
/*====================*/
/*====================*/
void Solve(void)
{
#ifndef ONLINE_JUDGE
    freopen("IN.txt", "r+", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; //cin >> T;
    while (T--)Solve();
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
