#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e3+5;
int n;
int p[maxn][maxn],f[maxn][maxn],a[maxn][maxn];
signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cin>>a[i][j];
        }
    }
    f[1][1]=a[1][1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(i==1&&j==1) continue;
            f[i][j]=f[i-1][j-1]+f[i-1][j];
        }
    }
    int ans=-100;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,f[n][i]);
    }
    cout<<ans;
    return 0;
}