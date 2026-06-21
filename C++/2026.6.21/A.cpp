#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+5;
const int mod=998244353;
int n,f[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    f[0]=1;
    f[1]=0;
    f[2]=0;
    for(int i=3;i<=n;i++)
    {
        f[i]=(f[i-1]+f[i-3])%mod;
    }
    cout<<f[n]<<endl;
    return 0;
}
