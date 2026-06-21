#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+5;

int n,q,fa[maxn];

int find(int x)
{
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

void merge(int x,int y)
{
    x=find(x);y=find(y);
    if(x!=y) fa[x]=y;
}

signed main()
{
    cin>>n>>q;
    for(int i=0;i<=n;i++) fa[i]=i;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        merge(l-1,r);
    }
    if(find(0)==find(n)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
