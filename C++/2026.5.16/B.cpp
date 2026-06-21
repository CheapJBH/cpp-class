#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
const int maxn=1e9;

signed main()
{
    int n,q;
    set<pair<int,int>> s;
    cin>>n>>q;
    for(int i=0;i<q;i++)
    {
        int l,r,a;
        cin>>a>>l>>r;
        if (a==1)
        {
            s.insert({l,r});
        }
        if (a==2)
        {
            s.erase({l,r});
        }
        if (a==3)
        {
            if(s.count({l,r})&&s.count({r,l})) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}