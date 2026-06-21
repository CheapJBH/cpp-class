#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+5;
int n;
int a[maxn],ans;
priority_queue<int,vector<int>,greater<int>>q;
signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int m;
        cin>>m;
        q.push(m);
    }
    while(q.size()>=2)
    {
        int b=0;
        b+=q.top();
        q.pop();
        b+=q.top();
        q.pop();
        q.push(b);
        ans+=b;
    }
    cout<<ans;
    return 0;
}