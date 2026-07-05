#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=1e8+5;
bool st[N];
int n,cnt;
/*====================*/
/*====================*/
void Solve(void)
{
    cin>>n;
    for (int i=2;i<N;i++)
    {
        if (st[i]) continue;
        for (int j=i+i;j<N;j+=i)
        {
            st[j]=true;
        }
    }
    for (int i=2;i<=n;i++)
    {
        if (st[i]==false) cnt++;
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
