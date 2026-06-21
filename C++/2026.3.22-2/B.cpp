#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6;
int f[maxn],pos,l,r;
string s;
signed main()
{
    cin>>s;
    int n=s.size();
    s=" "+s;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='('||s[i]=='[') continue;
        f[i-1];
        int p=i-f[i-1]-1;
        if(s[i]==')')
        {
            if(s[p]=='(') f[i]=f[i-1]+2+f[p-1];
        }
        else if(s[i]==']')
        {
            if(s[p]=='[') f[i]=f[i-1]+2+f[p-1];
        }
        if(f[i]>f[pos]) pos=i;
    }
    int l=pos-f[pos]+1,r=pos;
    for(int i=l;i<=r;i++) cout<<s[i];
    return 0;
}