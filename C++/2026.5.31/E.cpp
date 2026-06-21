#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=100005;
int a,b,p,cnt,prime[maxn],f[maxn];
bool vis[maxn];
int ffind(int x)
{
    if(f[x]==x)
    {
        return x;
    }
    return f[x]=ffind(f[x]);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b>>p;
    for(int i=0;i<=b-a;i++)
    {
        f[i]=i;
    }
    for(int i=2;i<=b;i++)
    {
        if(!vis[i])
        {
            prime[++cnt]=i;
            for(int j=i*i;j<=b;j+=i)
            {
                vis[j]=1;
            }
        }
    }
    for(int i=1;i<=cnt&&prime[i]<=b;i++)
    {
        if(prime[i]>=p)
        {
            int first=((a+prime[i]-1)/prime[i])*prime[i];
            first-=a;
            for(int j=first+prime[i];j<=b-a;j+=prime[i])
            {
                int fx=ffind(first),fy=ffind(j);
                if(fx!=fy)
                {
                    f[fx]=fy;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<=b-a;i++)
    {
        if(f[i]==i)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
