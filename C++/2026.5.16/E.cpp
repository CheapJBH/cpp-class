#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+5;
int n,m,a[maxn];
bool check(int x)
{
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=min(a[i],x);
        if(sum>m) return 0;
    }
    return 1;
}
signed main()
{
    cin>>n>>m;
    int sum_a=0,max_a=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum_a+=a[i];
        max_a=max(max_a,a[i]);
    }
    if(sum_a<=m)
    {
        cout<<"infinite"<<endl;
        return 0;
    }
    int lo=0,hi=max_a;
    while(lo<hi)
    {
        int mid=(lo+hi+1)>>1;
        if(check(mid)) lo=mid;
        else hi=mid-1;
    }
    cout<<lo<<endl;
    return 0;
}