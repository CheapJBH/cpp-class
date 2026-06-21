#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n;
signed main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        for(int j=2;j<=3e6;j++)
        {
            if(n%(j*j)==0)
            {
                cout<<j<<' '<<n/(j*j)<<endl;
                break;
            }
            if(n%j==0)
            {
                cout<<(int)sqrtl(n/j)<<' '<<j<<endl;
                break;
            }
        }
    }
    return 0;
}
