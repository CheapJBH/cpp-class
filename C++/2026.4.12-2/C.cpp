#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=1e7+5;
lnt m,f[N];
/*====================*/
/*====================*/
void Solve(void)
{
    cin>>m;
    memset(f,0x3f,sizeof(f));
    f[0]=0;
    for (int i=1;i<=30;i++)
    {
        lnt x=i*i*i*i;
        for (int j=x;j<=m;j++)
        {
            f[j]=min(f[j],f[j-x]+1);
        }
    }
    cout<<f[m];
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
