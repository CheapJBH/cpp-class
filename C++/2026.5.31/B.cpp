#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+5;
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
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        f[i]=i;
    }
    while(m--)
    {
        int op,x,y;
        cin>>op>>x>>y;
        int fx=ffind(x),fy=ffind(y);
        if(op==1)
        {
            f[fx]=fy;
        }
        else
        {
            if(fx==fy)
            {
                cout<<'Y'<<endl;
            }
            else
            {
                cout<<'N'<<endl;
            }
        }
    }
    return 0;
}
