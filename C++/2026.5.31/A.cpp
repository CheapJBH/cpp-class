#include<bits/stdc++.h>
using namespace std;
const int maxn=1e8+5;
bool st[maxn];
int n,cnt;
signed main()
{
    cin>>n;
    for(int i=2;i<maxn;i++)
    {
        if(st[i]) continue;
        for(int j=i+i;j<maxn;j+=i)
        {
            st[j]=true;
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(st[i]==false) cnt++;
    }
    cout<<cnt;
    return 0;
}