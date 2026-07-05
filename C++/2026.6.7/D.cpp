#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
lnt n,ans;
/*====================*/
/*====================*/
void Solve(void)
{
    cin>>n;
    for (int i=2;i*i<=n;i++)
    {
        if (n%i==0)
        {
            lnt cnt=0;
            while (n%i==0)
            {
                cnt++;
                n/=i;
            }
            lnt k=0;
            for (int j=1;j*(j+1)/2<=cnt;j++)
            {
                k=j;
            }
            ans+=k;
        }
    }
    if (n>1)
    {
        ans++;
    }
    cout<<ans<<endl;
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
