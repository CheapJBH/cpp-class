#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
signed main()
{
    cin>>n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            int cnt=0;
            while(n%i==0)
            {
                cnt++;
                n/=i;
            }
            int k=0;
            for(int j=1;j*(j+1)/2<=cnt;j++)
            {
                k=j;
            }
            ans+=k;
        }
    }
    if(n>1)
    {
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
