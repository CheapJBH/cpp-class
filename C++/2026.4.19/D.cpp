#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long n,m,f[maxn];
long long a[maxn],b[maxn];
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=maxn;i++)
    {
        f[i]=1e9;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            f[j]=min(f[j],f[max((long long)(0),j-a[i])]+b[i]);
        }
    }
    cout<<f[m];
    return 0;
}