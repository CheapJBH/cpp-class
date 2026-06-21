#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e3+5;
int n;
int ans;
char f[maxn][maxn],a[maxn];
signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j!=i) f[i][j]=1e15;
            else f[i][j]=0;
        }
    }
    // 求f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+output(i,j));
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            for(int k=i;k<=j;k++)
            {
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+output(i,j));
            }
        }
    }
    cout<<f[1][n];
    return 0;
}