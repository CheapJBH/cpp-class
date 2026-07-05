#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
typedef pair<lnt,lnt> pii;
/*====================*/
/*====================*/
void Solve(void)
{
    lnt q;
    cin>>q;
    deque<pii> dq;
    while (q--)
    {
        lnt op;
        cin>>op;
        if (op==1)
        {
            lnt x,c;
            cin>>x>>c;
            dq.push_back({x,c});
        }
        else
        {
            lnt c;
            cin>>c;
            lnt sum=0;
            while (c>0)
            {
                auto &f=dq.front();
                if (f.second>c)
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
}
/*====================*/
int main()
{
#ifndef ONLINE_JUDGE
    freopen("IN.txt", "r+", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; //cin >> T;
    while (T--)Solve();
    return 0;
}
