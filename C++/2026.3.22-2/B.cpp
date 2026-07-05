#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=1e6;
lnt f[N],pos,l,r;
string s;
/*====================*/
/*====================*/
void Solve(void)
{
    cin>>s;
    lnt n=s.size();
    s=" "+s;
    for (int i=1;i<=n;i++)
    {
        if (s[i]=='('||s[i]=='[') continue;
        f[i-1];
        lnt p=i-f[i-1]-1;
        if (s[i]==')')
        {
            if (s[p]=='(') f[i]=f[i-1]+2+f[p-1];
        }
        else if (s[i]==']')
        {
            if (s[p]=='[') f[i]=f[i-1]+2+f[p-1];
        }
        if (f[i]>f[pos]) pos=i;
    }
    lnt l=pos-f[pos]+1,r=pos;
    for (int i=l;i<=r;i++) cout<<s[i];
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
