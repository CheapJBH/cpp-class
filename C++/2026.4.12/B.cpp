#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=4e3+5;
int n,t,m,f[maxn];
int a[maxn],b[maxn];
signed main()
{
    cin>>t>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=t;j>=a[i];j--)
        {
            if(j-a[i]>=0) f[j]=max(f[j],f[j-a[i]]+b[i]);
        }
    }
    cout<<f[t];
    return 0;
}