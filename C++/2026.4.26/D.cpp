#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=1e3+5;
lnt n;
lnt ans;
char f[N][N],a[N];
/*====================*/
/*====================*/
void Solve(void)
{
    cin>>n;
    for (int i=1;i<=n;i++) 
    {
        cin>>a[i];
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (j!=i) f[i][j]=1e15;
            else f[i][j]=0;
        }
    }
    // 求f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+output(i,j));
    for (int len=2;len<=n;len++)
    {
        for (int i=1;i+len-1<=n;i++)
        {
            lnt j=i+len-1;
            for (int k=i;k<=j;k++)
            {
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+output(i,j));
            }
        }
    }
    cout<<f[1][n];
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
