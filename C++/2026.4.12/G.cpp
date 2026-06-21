#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=4e5+5;
int n,v,f[maxn];
int a[maxn],b[maxn];
signed main()
{
    cin>>v>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=v;j>=a[i];j--)
        {
            if(j-a[i]>=0) f[j]=max(f[j],f[j-a[i]]+a[i]);
        }
    }
    cout<<f[v];
    return 0;
}