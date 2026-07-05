#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N=1e5+5;
lnt n,t;
struct node{
    lnt v,m;
    double c;
    friend bool operator < (node p,node q)
    {
        return p.c<q.c;
    }
}a[N];
double cnt,res;
/*====================*/
/*====================*/
void Solve(void)
{
    cin>>n>>t;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].m>>a[i].v;
        a[i].c=1.0*a[i].v/a[i].m;
    }
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    lnt j=1;
    while (j<=n)
    {
        if (cnt+a[j].m<=t) cnt+=a[j].m,res+=a[j].v;
        else{
            res+=(t-cnt)*a[j].c;
            break;
        }
        j++;
    }
    cout<<fixed<<setprecision(2)<<res;
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
