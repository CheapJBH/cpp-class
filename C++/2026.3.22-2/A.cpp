#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=1e3+5;
lnt n,ans;
lnt f[N][N];
/*====================*/
/*====================*/
void Solve(void)
{
    cin>>n;
    f[0][0]=1;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=i;j++)
        {
            for (int k=0;k<=j-1;k++) f[i][j]+=f[i-j][k];
        }
    }
    for (int i=0;i<=n;i++) ans+=f[n][i];
    ans-=1;
    cout<<ans;
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
