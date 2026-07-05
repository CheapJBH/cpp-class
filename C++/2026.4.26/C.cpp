#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=1e3+5;
lnt n;
lnt a[N],ans,p[N],f[N][N];
lnt output(lnt l,lnt r)
{
    return p[r]-p[l-1];
}
/*====================*/
/*====================*/
void Solve(void)
{
    cin>>n;
    for (int i=1;i<=n;i++) 
    {
        cin>>a[i];
        p[i]=p[i-1]+a[i];
    }
    for (int i=n+1;i<=2*n;i++)
    {
        a[i]=a[i-n];
        p[i]=p[i-1]+a[i];
    }
    n*=2;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (j!=i) f[i][j]=1e15;
            else f[i][j]=0;
        }
    }
    // 求f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+output(i,j));
    for (int len=2;len<=n/2;len++)
    {
        for (int i=1;i+len-1<=n;i++)
        {
            lnt j=i+len-1;
            for (int k=i;k<j;k++)
            {
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+output(i,j));
            }
        }
    }
    lnt cnt=1e15;
    for (int i=1;i<=n/2;i++)
    {
        cnt=min(f[i][n/2+i-1],cnt);
    }
    cout<<cnt<<endl;

    
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (j!=i) f[i][j]=-1e15;
            else f[i][j]=0;
        }
    }
    for (int len=2;len<=n/2;len++)
    {
        for (int i=1;i+len-1<=n;i++)
        {
            lnt j=i+len-1;
            for (int k=i;k<j;k++)
            {
                f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]+output(i,j));
            }
        }
    }
    cnt=-1e15;
    for (int i=1;i<=n/2;i++)
    {
        cnt=max(f[i][n/2+i-1],cnt);
    }
    cout<<cnt;
}
/*====================*/
int main()
{
#ifndef ONLINE_JUDGE
    freopen("IN.txt", "r+", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; //cin >> T;
    while (T--)Solve();
    return 0;
}
