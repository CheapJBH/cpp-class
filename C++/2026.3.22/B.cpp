#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e3+5;
int n,t,a[maxn],f[maxn],p[maxn];

signed main()
{
    cin>>n>>t;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        p[i]=p[i-1]+a[i];

    }
    for(int i=1;i<=n;i++)
    {
        int ans=n*n*a[i]+f[i-1];
        for(int j=1;j<i;j++)
        {
            if(a[i]+a[j]>t) continue;
            ans=min(ans,(a[i]+a[j])*(p[i]-p[j-1])+f[j-1]);
        }
    }
    cout<<f[n];
    return 0;
    
}