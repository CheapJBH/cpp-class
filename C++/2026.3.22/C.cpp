#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=2e3+5;
lnt f[N][N];
lnt g;
string a,b;
/*====================*/
/*====================*/
void Solve(void)
{
    cin>>g;
    for (int k=1;k<=g;k++)
    {
        memset(f,0,sizeof(f));
        cin>>a>>b;
        lnt n=a.size(),m=b.size();
        a=" "+a,b=" "+b;    
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                if (a[i]==b[j]) f[i][j]=f[i-1][j-1]+1;
                else f[i][j]=max(f[i-1][j],f[i][j-1]);
                
            }
        }
        cout<<f[n][m]<<endl;
    }
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
