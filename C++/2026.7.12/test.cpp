#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
void Solve(void)
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    map<int,int>mp;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            mp[j]++;
            cout<<mp[j]<<" ";
        }
        cout<<endl;
    }
    int k=1;
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<k++<<" ";
        }
        cout<<endl;
    }
    int p=1; 
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<p++<<" ";
        }
        cout<<endl;
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