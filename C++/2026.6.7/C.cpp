#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
lnt t,n;
/*====================*/
/*====================*/
void Solve(void)
{
    cin>>t;
    for (int i=1;i<=t;i++)
    {
        cin>>n;
        for (int j=2;j<=3e6;j++)
        {
            if (n%(j*j)==0)
            {
                cout<<j<<' '<<n/(j*j)<<endl;
                break;
            }
            if (n%j==0)
            {
                cout<<(lnt)sqrtl(n/j)<<' '<<j<<endl;
                break;
            }
        }
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
