#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n;
    string s;
    cin>>n>>s;
    vector<int> a(n);
    for(int i=0;i<n;i++) a[i]=i+1;
    for(int k=0;k<n;k++)
    {
        if(s[k]=='o')
        {
            for(int j=0;j<k+1-j;j++)
            {
                swap(a[j],a[k-j]);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(i) cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
    return 0;
}
