#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e3+5;
int n,r[maxn][maxn],f[maxn];
signed main()
{
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            cin>>r[i][j];
        }
    }
    for(int i=1;i<=n;i++) f[i]=1e6;
    f[1]=0;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i-1;j++) f[i]=min(f[i],f[j]+r[j][i]);
    }
    cout<<f[n];
    return 0;

}