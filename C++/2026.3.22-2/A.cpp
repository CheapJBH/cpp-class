#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e3+5;
int n,ans;
int f[maxn][maxn];
signed main()
{
    cin>>n;
    f[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            for(int k=0;k<=j-1;k++) f[i][j]+=f[i-j][k];
        }
    }
    for(int i=0;i<=n;i++) ans+=f[n][i];
    ans-=1;
    cout<<ans;
    return 0;
}