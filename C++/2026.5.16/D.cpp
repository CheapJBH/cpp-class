#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=2e5+5;
lnt w[N],p[N];
lnt n,Q;
/*====================*/
/*====================*/
void Solve(void)
{
    cin>>n>>Q;
    for (int i=1;i<=n;i++) cin>>w[i],p[i]=p[i-1]+w[i];
    sort(w+1,w+n+1);
    for (int i=1;i<=n;i++) p[i]=p[i-1]+w[i];
    while (Q--)
    {
        lnt x;
        cin>>x;
        lnt pos=lower_bound(w+1,w+n+1,x)-w;
        lnt sum1=p[pos-1],sum2=p[n]-p[pos-1];
        lnt sum=((pos-1)*x-sum1)+(sum2-(n-pos+1)*x);
        cout<<sum<<endl;
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
