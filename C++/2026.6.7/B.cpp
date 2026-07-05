#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=1e3+5;
const int mod=1e9+7;
lnt n,a[N];
lnt tot,p[N],cnt[N];
/*====================*/
/*====================*/
void Solve(void)
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (int i=1;i<=n;i++)
    {
        lnt x=a[i];
        for (int j=2;j*j<=x;j++)
        {
            if (x%j==0)
            {
                lnt pos=0;
                for (int k=1;k<=tot;k++)
                {
                    if (p[k]==j)
                    {
                        pos=k;
                        break;
                    }
                }
                if (pos==0)
                {
                    p[++tot]=j;
                    pos=tot;
                }
                while (x%j==0)
                {
                    cnt[pos]++;
                    x/=j;
                }
            }
        }
        if (x>1)
        {
            lnt pos=0;
            for (int k=1;k<=tot;k++)
            {
                if (p[k]==x)
                {
                    pos=k;
                    break;
                }
            }
            if (pos==0)
            {
                p[++tot]=x;
                pos=tot;
            }
            cnt[pos]++;
        }
    }
    lnt ans=1;
    for (int i=1;i<=tot;i++)
    {
        ans=ans*(cnt[i]+1)%mod;
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
