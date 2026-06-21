#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e7+5;
int n,m,f[maxn];
int a[maxn],b[maxn];
signed main()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i]>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=a[i];j<=m;j++)
        {
            if(j-a[i]>=0) f[j]=max(f[j],f[j-a[i]]+b[i]);
        }
    }
    cout<<f[m];
    return 0;
}