#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e4+5;

int f[maxn],a[maxn];
signed main()
{
    int n;
    cin>>n;
    f[0]=1;
    f[1]=1;
    f[2]=2;
    for(int i=3;i<=n;i++)
    {
        f[i]=f[i-1]+f[i-2]+f[i-3];
    }
    cout<<f[n];
    return 0;
}