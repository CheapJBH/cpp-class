#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=2005;

lnt n,m;
vector<lnt> g[N];
lnt vis[N];
/*====================*/
/*====================*/
void Solve(void)
{
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        lnt u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }
    lnt total=0;
    for (int s=1;s<=n;s++)
    {
        lnt cnt=0;
        queue<lnt> q;
        q.push(s);
        vis[s]=s;
        while (!q.empty())
        {
            lnt u=q.front();q.pop();
            for (int v:g[u])
            {
                if (vis[v]!=s)
                {
                    vis[v]=s;
                    q.push(v);
                    cnt++;
                }
            }
        }
        total+=cnt;
    }
    cout<<total-m<<endl;
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
