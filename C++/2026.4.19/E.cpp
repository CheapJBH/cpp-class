#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+5;
int s[maxn];
int a[15][maxn],sum,ans;
bool f[maxn];
signed main()
{
    for(int i=1;i<=4;i++) cin>>s[i];
    for(int k=1;k<=4;k++)
    {
        for(int i=1;i<=s[k];i++) cin>>a[k][i];
        for(int i=1;i<=s[k];i++) sum+=a[k][i];
        for(int i=0;i<=sum;i++) f[i]=false;
        f[0]=true;
        for(int i=1;i<=s[k];i++)
        {
            for(int j=sum;j>=a[k][i];j--) f[j]|=f[j-a[k][i]];
        }
        for(int i=(sum+1)/2;i<=sum;i++)
        {
            if(f[i])
            {
                ans+=i;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
