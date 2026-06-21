#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n;
    cin>>n;
    map<int,vector<int>> mp;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        mp[x].push_back(i);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int l,r,x;
        cin>>l>>r>>x;
        auto it=mp.find(x);
        if(it==mp.end())
        {
            cout<<0<<endl;
            continue;
        }
        auto &v=it->second;
        int cnt=upper_bound(v.begin(),v.end(),r)-lower_bound(v.begin(),v.end(),l);
        cout<<cnt<<endl;
    }
    return 0;
}
