#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pii;

signed main()
{
    int q;
    cin>>q;
    deque<pii> dq;
    while(q--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int x,c;
            cin>>x>>c;
            dq.push_back({x,c});
        }
        else
        {
            int c;
            cin>>c;
            int sum=0;
            while(c>0)
            {
                auto &f=dq.front();
                if(f.second>c)
                {
                    sum+=f.first*c;
                    f.second-=c;
                    c=0;
                }
                else
                {
                    sum+=f.first*f.second;
                    c-=f.second;
                    dq.pop_front();
                }
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}
