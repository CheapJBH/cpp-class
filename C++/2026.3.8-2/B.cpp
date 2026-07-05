#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=1e6+5;
string s;
lnt p[N],f[N],a[N];
/*====================*/
/*====================*/
void Solve(void)
{
    cin>>s;
    lnt n=s.size();
    s=" "+s;
    
    for (int i=1;i<=n;i++)
    {
        a[i]=s[i]-'a'+1;
    }
    f[0]=0;
    f[1]=a[1];
    if (n>=2) f[2]=a[2];
    for (int i=3;i<=n;i++)
    {
        f[i]=max(f[i-3],f[i-2])+a[i];
    }
    cout<<max(f[n],f[n-1])<<endl;
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
