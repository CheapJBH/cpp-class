#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=1e5+5;
lnt s[N];
lnt a[15][N],sum,ans;
bool f[N];
/*====================*/
/*====================*/
void Solve(void)
{
    for (int i=1;i<=4;i++) cin>>s[i];
    for (int k=1;k<=4;k++)
    {
        for (int i=1;i<=s[k];i++) cin>>a[k][i];
        for (int i=1;i<=s[k];i++) sum+=a[k][i];
        for (int i=0;i<=sum;i++) f[i]=false;
        f[0]=true;
        for (int i=1;i<=s[k];i++)
        {
            for (int j=sum;j>=a[k][i];j--) f[j]|=f[j-a[k][i]];
        }
        for (int i=(sum+1)/2;i<=sum;i++)
        {
            if (f[i])
            {
                ans+=i;
                break;
            }
        }
    }
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
