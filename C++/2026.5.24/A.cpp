#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e2+5;
int n,k,d,a[maxn],f[maxn][maxn][maxn];
signed main()
{
    cin>>n>>k>>d;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<=100;i++)
    {
        for(int j=0;j<=100;j++)
        {
            for(int k=0;k<=100;k++)
            {
                f[i][j][k]=-1e18;  
            }
        }
    }
    f[0][0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            for(int g=0;g<=d;g++)
            {
                if(j==0)
                {
                    f[i][j][g]=f[i-1][j][g];
                }
                else f[i][j][g]=max(f[i-1][j][g],f[i-1][j-1][(g-a[i]%d+d)%d]+a[i]);
            }
        }
    }
    if(f[n][k][0]<0) cout<<-1;
    else cout<<f[n][k][0];
    return 0;
}