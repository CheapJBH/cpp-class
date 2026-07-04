#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n;
    string s;
    cin>>n>>s;
    deque<int> dq;
    dq.push_back(1);
    bool rev=false;
    for(int i=1;i<n;i++)
    {
        if(s[i]=='o')
        {
            if(rev) dq.push_front(i+1);
            else dq.push_back(i+1);
            rev=!rev;
        }
        else
        {
            if(rev) dq.push_front(i+1);
            else dq.push_back(i+1);
        }
    }
    if(rev)
    {
        for(auto it=dq.rbegin();it!=dq.rend();it++)
        {
            if(it!=dq.rbegin()) cout<<" ";
            cout<<*it;
        }
    }
    else
    {
        for(auto it=dq.begin();it!=dq.end();it++)
        {
            if(it!=dq.begin()) cout<<" ";
            cout<<*it;
        }
    }
    cout<<endl;
    return 0;
}
