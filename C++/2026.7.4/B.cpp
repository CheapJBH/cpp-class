#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int x,y,l,r,a,b;
    cin>>x>>y>>l>>r>>a>>b;
    int overlap=max(0LL,min(b,r)-max(a,l));
    int total=b-a;
    cout<<(total-overlap)*y+overlap*x<<endl;
    return 0;
}
