#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+5;
int n;
struct node{
    int x,y;
    friend bool operator <(node p,node q)
    {
        if(p.x!=q.x) return p.x<q.x;
        return p.y<q.y;
    }
}w[maxn];
int suf_max[maxn],suf_min[maxn];
bool check (int mid)
{
    for(int i=1;i<=n;i++)
    {
        int pos=lower_bound(w+1,w+n+1,node{w[i].x+mid,0})-w;
        if(pos ==n+1) continue;
        int max_Y=suf_max[pos],min_Y=suf_min[pos];
        if(max_Y-w[i].y>=mid || w[i].y-min_Y>=mid) return true;
    }
}
signed main()
{
    
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i].x>>w[i].y;
    }
    sort(w+1,w+n+1);
    suf_max[n]=suf_min[n]=w[n].y;
    for(int i=n-1;i>=1;i--)
    {

    }
    int l=0,r=2e9;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid)) l=mid+1;
        else r=mid-1;
    }
    cout<<r;
    return 0;
}