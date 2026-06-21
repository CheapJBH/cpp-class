#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=4e5+5;
int n,m,f[maxn];
int a[maxn],b[maxn];
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=a[i];j--)
        {
            if(j-a[i]>=0) f[j]=max(f[j],f[j-a[i]]+b[i]);
        }
    }
    cout<<f[m];
    return 0;
}