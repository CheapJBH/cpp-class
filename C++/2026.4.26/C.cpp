#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e3+5;
int n;
int a[maxn],ans,p[maxn],f[maxn][maxn];
int output(int l,int r)
{
    return p[r]-p[l-1];
}
signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        p[i]=p[i-1]+a[i];
    }
    for(int i=n+1;i<=2*n;i++)
    {
        a[i]=a[i-n];
        p[i]=p[i-1]+a[i];
    }
    n*=2;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j!=i) f[i][j]=1e15;
            else f[i][j]=0;
        }
    }
    // 求f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+output(i,j));
    for(int len=2;len<=n/2;len++)
    {
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            for(int k=i;k<j;k++)
            {
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+output(i,j));
            }
        }
    }
    int cnt=1e15;
    for(int i=1;i<=n/2;i++)
    {
        cnt=min(f[i][n/2+i-1],cnt);
    }
    cout<<cnt<<endl;


    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j!=i) f[i][j]=-1e15;
            else f[i][j]=0;
        }
    }
    for(int len=2;len<=n/2;len++)
    {
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            for(int k=i;k<j;k++)
            {
                f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]+output(i,j));
            }
        }
    }
    cnt=-1e15;
    for(int i=1;i<=n/2;i++)
    {
        cnt=max(f[i][n/2+i-1],cnt);
    }
    cout<<cnt;
    return 0;
}