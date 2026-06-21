#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1005;
int n,m,f[maxn];
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>n)
    {
        if(n==0)
        {
            break;
        }
        cin>>m;
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
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(f[i]==i)
            {
                cnt++;
            }
        }
        cout<<cnt-1<<endl;
    }
    return 0;
}
