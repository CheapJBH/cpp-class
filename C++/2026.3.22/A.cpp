#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e3+5;
int m,n,a[maxn][maxn],f[maxn][maxn];

signed main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        } 
    }
    for(int j=1;j<=n;j++)
    {
        for(int i=1;i<=m;i++)
        {
            if(i==1) f[i][j]=min(f[i][j-1],f[m][j-1])+a[i][j];
            else f[i][j]=min(f[i][j-1],f[i-1][j-1])+a[i][j];
        }
    }
    int ans=1e9;
    for(int i=1;i<=m;i++)
    {
        ans=min(ans,f[i][n]);
        
    }
    cout<<ans;
    return 0;
    
}