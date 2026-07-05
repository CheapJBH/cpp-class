#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=2e5+5;

lnt n,q,fa[N];

lnt find(lnt x)
{
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

void merge(lnt x,lnt y)
{
    x=find(x);y=find(y);
    if (x!=y) fa[x]=y;
}
/*====================*/
/*====================*/
void Solve(void)
{
    cin>>n>>q;
    for (int i=0;i<=n;i++) fa[i]=i;
    while (q--)
    {
        lnt l,r;
        cin>>l>>r;
        merge(l-1,r);
    }
    if (find(0)==find(n)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
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
