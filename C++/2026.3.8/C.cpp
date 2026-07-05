#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=2e5+5;
lnt n;
struct node{
    lnt x,y;
    friend bool operator <(node p,node q)
    {
        if (p.x!=q.x) return p.x<q.x;
        return p.y<q.y;
    }
}w[N];
lnt suf_max[N],suf_min[N];
bool check (lnt mid)
{
    for (int i=1;i<=n;i++)
    {
        lnt pos=lower_bound(w+1,w+n+1,node{w[i].x+mid,0})-w;
        if (pos ==n+1) continue;
        lnt max_Y=suf_max[pos],min_Y=suf_min[pos];
        if (max_Y-w[i].y>=mid || w[i].y-min_Y>=mid) return true;
    }
}
/*====================*/
/*====================*/
void Solve(void)
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>w[i].x>>w[i].y;
    }
    sort(w+1,w+n+1);
    suf_max[n]=suf_min[n]=w[n].y;
    for (int i=n-1;i>=1;i--)
    {

    }
    lnt l=0,r=2e9;
    while (l<=r)
    {
        lnt mid=(l+r)/2;
        if (check(mid)) l=mid+1;
        else r=mid-1;
    }
    cout<<r;
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
