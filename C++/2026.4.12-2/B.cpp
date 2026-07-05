#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=1e4+5;
lnt m,f[N];
bool isprime(lnt x)
{
    bool l=true;
    for (int i=2;i<=x/2;i++)
    {
        if (x%i==0) 
        {
            l=false;
            break;
        }
    }
    return l;
}
/*====================*/
/*====================*/
void Solve(void)
{
    cin>>m;
    f[0]=1;
    for (int i=2;i<=1000;i++)
    {
        if (!isprime(i)) continue;
        for (int j=i;j<=m;j++)
        {
            f[j]=f[j]+f[j-i];
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
