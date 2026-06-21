#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n;
    cin>>n;
    map<int,int> cnt;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        cnt[x]++;
        sum+=x;
    }
    int q;
    cin>>q;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        if(x==y)
        {
            cout<<sum<<endl;
            continue;
        }
        auto it=cnt.find(x);
        if(it==cnt.end())
        {
            cout<<sum<<endl;
            continue;
        }
        int cx=it->second;
        sum+=cx*(y-x);
        cnt[y]+=cx;
        cnt.erase(it);
        cout<<sum<<endl;
    }
    return 0;
}