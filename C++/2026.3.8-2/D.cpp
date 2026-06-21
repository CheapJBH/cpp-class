#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e3+5;
int n,m;
int p[maxn],f[maxn][maxn],a[maxn][maxn];
signed main()
{
    cin>>n>>m;
    f[1][1]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==1&&j==1) continue;
            if(i%2==0&&j%2==0)
            {
                f[i][j]=0;
            }
            else
            {
                f[i][j]=f[i-1][j]+f[i][j-1];
            }
        }
    }
    cout<<f[n][m];
    return 0;
}