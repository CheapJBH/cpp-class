#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=4e5+5;
bool f[N];
lnt a[]={0,1,2,3,5,10,20},cnt;
/*====================*/
/*====================*/
void Solve(void)
{
    f[0]=true;
    for (int i=1;i<=6;i++)
    {
        lnt m;
        cin>>m;
        while (m -- )
        {
            for (int j=1000;j>=a[i];j--)
            {
                f[j]|=f[j-a[i]];
            }
        }
        cnt=0;
        for (int i=1;i<=1000;i++)
        {
            if (f[i]) cnt++;
        }
    }
    
    cout<<"Total="<<cnt;
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
