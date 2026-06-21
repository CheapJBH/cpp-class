#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n,cnt=0;
    string s;
    cin>>s>>n;
    int maxn=s.size();
    reverse(s.begin(),s.end());
    for(int i=0;i<maxn;i++)
    {
        if(s[i]=='1') cnt+=(1LL<<i);
    }
    if(cnt>n)
    {
        cout<<-1;
        return 0;
    }
    if(cnt==n)
    {
        cout<<cnt;
        return 0;
    }
    for(int i=maxn-1;i>=0;i--)
    {
        if(s[i]=='?'&&(cnt+(1LL<<i))<=n) cnt+=(1LL<<i);
    }
    return 0;
    
}