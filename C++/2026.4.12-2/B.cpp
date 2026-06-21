#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e4+5;
int m,f[maxn];
bool isprime(int x)
{
    bool l=true;
    for(int i=2;i<=x/2;i++)
    {
        if(x%i==0) 
        {
            l=false;
            break;
        }
    }
    return l;
}
signed main()
{
    cin>>m;
    f[0]=1;
    for(int i=2;i<=1000;i++)
    {
        if(!isprime(i)) continue;
        for(int j=i;j<=m;j++)
        {
            f[j]=f[j]+f[j-i];
        }
    }
    cout<<f[m];
    return 0;
}
