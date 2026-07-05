#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=100005;
lnt a,b,p,cnt,prime[N],f[N];
bool vis[N];
lnt ffind(lnt x)
{
    if (f[x]==x)
    {
        return x;
    }
    return f[x]=ffind(f[x]);
}
/*====================*/
/*====================*/
void Solve(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b>>p;
    for (int i=0;i<=b-a;i++)
    {
        f[i]=i;
    }
    for (int i=2;i<=b;i++)
    {
        if (!vis[i])
        {
            prime[++cnt]=i;
            for (int j=i*i;j<=b;j+=i)
            {
                vis[j]=1;
            }
        }
    }
    for (int i=1;i<=cnt&&prime[i]<=b;i++)
    {
        if (prime[i]>=p)
        {
            lnt first=((a+prime[i]-1)/prime[i])*prime[i];
            first-=a;
            for (int j=first+prime[i];j<=b-a;j+=prime[i])
            {
                lnt fx=ffind(first),fy=ffind(j);
                if (fx!=fy)
                {
                    f[fx]=fy;
                }
            }
        }
    }
    lnt ans=0;
    for (int i=0;i<=b-a;i++)
    {
        if (f[i]==i)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
}
/*====================*/
int main()
{
#ifndef ONLINE_JUDGE
    freopen("IN.txt", "r+", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; //cin >> T;
    while (T--)Solve();
    return 0;
}
