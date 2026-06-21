#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+5;
signed main()
{
    int n,m,res=0;
    cin>>n>>m;
    queue<int> q;
    map<int,bool> mp;
    while(m--)
    {
        int x;
        cin>>x;
        if(mp[x]==true) continue;
        q.push(x),mp[x]=true,res++;
        if(q.size()>n)
        {
            int t=q.front();
            mp[t]=false,q.pop();
        }
    }
    cout<<res<<endl;
    return 0;
}