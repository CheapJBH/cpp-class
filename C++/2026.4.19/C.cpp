#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e3+5;
int n,t,v,f[maxn][maxn];
int a[maxn],b[maxn];
signed main()
{
    cin>>n>>v>>t;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=v;j>=a[i];j--)
        {
            for(int k=t;k>=b[i];k--)
            {
                f[j][k]=max(f[j][k],f[j-a[i]][k-b[i]]+1);
            }
        }
    }
    cout<<f[v][t];
    return 0;
}