#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+5;
string s;
int p[maxn],f[maxn],a[maxn];
signed main()
{
    cin>>s;
    int n=s.size();
    s=" "+s;
    
    for(int i=1;i<=n;i++)
    {
        a[i]=s[i]-'a'+1;
    }
    f[0]=0;
    f[1]=a[1];
    if(n>=2) f[2]=a[2];
    for(int i=3;i<=n;i++)
    {
        f[i]=max(f[i-3],f[i-2])+a[i];
    }
    cout<<max(f[n],f[n-1])<<endl;
    return 0;
}