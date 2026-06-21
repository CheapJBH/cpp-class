#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+5;
int n,m,a[maxn],p1[maxn],p2[maxn];
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        p1[i]=p1[i-1]+a[i];
        p2[i]=p2[i-1]+(i*a[i]);
    }
    int res=-1e18;
    for(int i=m;i<=n;i++)
    {
        int sum=(p2[i]-p2[i-m])-(i-m)*(p1[i]-p1[i-m]);
        res=max(sum,res);
    }
    cout<<res<<endl;
    return 0;
}