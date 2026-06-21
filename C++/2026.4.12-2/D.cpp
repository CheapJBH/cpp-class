#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=4e5+5;
bool f[maxn];
int a[]={0,1,2,3,5,10,20},cnt;
signed main()
{
    f[0]=true;
    for(int i=1;i<=6;i++)
    {
        int m;
        cin>>m;
        while(m -- )
        {
            for(int j=1000;j>=a[i];j--)
            {
                f[j]|=f[j-a[i]];
            }
        }
        cnt=0;
        for(int i=1;i<=1000;i++)
        {
            if(f[i]) cnt++;
        }
    }
    
    cout<<"Total="<<cnt;
    return 0;
}