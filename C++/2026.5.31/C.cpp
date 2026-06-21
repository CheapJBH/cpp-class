#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+5;
int n,m,q,f[maxn];
int ffind(int x)
{
    if(f[x]==x)
    {
        return x;
    }
    return f[x]=ffind(f[x]);
}
signed main()
{
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        f[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        int fx=ffind(x),fy=ffind(y);
        if(fx!=fy)
        {
            f[fx]=fy;
        }
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        int fx=ffind(x),fy=ffind(y);
        if(fx==fy)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    return 0;
}
