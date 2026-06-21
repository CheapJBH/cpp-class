#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e3+5;
const int mod=1e9+7;
int n,a[maxn];
int tot,p[maxn],cnt[maxn];
signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        int x=a[i];
        for(int j=2;j*j<=x;j++)
        {
            if(x%j==0)
            {
                int pos=0;
                for(int k=1;k<=tot;k++)
                {
                    if(p[k]==j)
                    {
                        pos=k;
                        break;
                    }
                }
                if(pos==0)
                {
                    p[++tot]=j;
                    pos=tot;
                }
                while(x%j==0)
                {
                    cnt[pos]++;
                    x/=j;
                }
            }
        }
        if(x>1)
        {
            int pos=0;
            for(int k=1;k<=tot;k++)
            {
                if(p[k]==x)
                {
                    pos=k;
                    break;
                }
            }
            if(pos==0)
            {
                p[++tot]=x;
                pos=tot;
            }
            cnt[pos]++;
        }
    }
    int ans=1;
    for(int i=1;i<=tot;i++)
    {
        ans=ans*(cnt[i]+1)%mod;
    }
    cout<<ans<<endl;
    return 0;
}
