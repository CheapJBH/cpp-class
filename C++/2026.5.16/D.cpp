#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+5;
int w[maxn],p[maxn];
int n,Q;
signed main()
{
    cin>>n>>Q;
    for(int i=1;i<=n;i++) cin>>w[i],p[i]=p[i-1]+w[i];
    sort(w+1,w+n+1);
    for(int i=1;i<=n;i++) p[i]=p[i-1]+w[i];
    while(Q--)
    {
        int x;
        cin>>x;
        int pos=lower_bound(w+1,w+n+1,x)-w;
        int sum1=p[pos-1],sum2=p[n]-p[pos-1];
        int sum=((pos-1)*x-sum1)+(sum2-(n-pos+1)*x);
        cout<<sum<<endl;
    }
    return 0;
}