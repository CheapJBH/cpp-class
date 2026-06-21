#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6;
int f[maxn],s[maxn],n,w[maxn];
signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    f[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(w[i]>w[i-1]) f[i]=f[i-1]+1;
        else f[i]=1;
    }
    for(int i=2;i<=n;i++)
    {
        if(w[i]>w[i-1]) f[i]=f[i-1]+1;
        else f[i]=1;
    }
    s[n]=1;
    int res=0;
    for(int i=1;i<=n;i++) max(res,f[i]);
    for(int i=2;i<=n;i++) max(res,f[i-1]+1);
    for(int i=1;i<=n-1;i++) max(res,s[i+1]+1);
    for(int i=2;i<=n-1;i++) if(w[i+1]-w[i-1]>=2) max(res,f[i-1]+1+s[i+1]);
    cout<<res;
    return 0;

}