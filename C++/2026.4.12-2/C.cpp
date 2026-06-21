#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e7+5;
int m,f[maxn];

signed main()
{
    cin>>m;
    memset(f,0x3f,sizeof(f));
    f[0]=0;
    for(int i=1;i<=30;i++)
    {
        int x=i*i*i*i;
        for(int j=x;j<=m;j++)
        {
            f[j]=min(f[j],f[j-x]+1);
        }
    }
    cout<<f[m];
    return 0;
    
}
