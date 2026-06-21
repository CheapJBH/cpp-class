#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+5;
int n,t;
struct node{
    int v,m;
    double c;
    friend bool operator < (node p,node q)
    {
        return p.c<q.c;
    }
}a[maxn];
double cnt,res;

signed main()
{
    cin>>n>>t;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].m>>a[i].v;
        a[i].c=1.0*a[i].v/a[i].m;
    }
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    int j=1;
    while(j<=n)
    {
        if(cnt+a[j].m<=t) cnt+=a[j].m,res+=a[j].v;
        else{
            res+=(t-cnt)*a[j].c;
            break;
        }
        j++;
    }
    cout<<fixed<<setprecision(2)<<res;
    return 0;
}