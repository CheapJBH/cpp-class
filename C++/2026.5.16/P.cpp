#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int MOD=1e9+7;

struct mat
{
    long long a[3][3];
    mat(){memset(a,0,sizeof(a));}
    mat operator*(const mat &o)const
    {
        mat r;
        for (int k=0;k<3;k++)
        {
            for (int i=0;i<3;i++)
            {
                if (!a[i][k]) continue;
                for (int j=0;j<3;j++)
                {
                    if (!o.a[k][j]) continue;
                    r.a[i][j]=(r.a[i][j]+a[i][k]*o.a[k][j])%MOD;
                }
            }
        }
        return r;
    }
};

mat qpow(mat m,lnt p)
{
    mat r;
    for (int i=0;i<3;i++) r.a[i][i]=1;
    while (p)
    {
        if (p&1) r=r*m;
        m=m*m;
        p>>=1;
    }
    return r;
}
/*====================*/
/*====================*/
void Solve(void)
{
    lnt n;
    cin>>n;
    if (n<3)
    {
        if (n==0) cout<<1<<endl;
        else cout<<0<<endl;
        return 0;
    }
    mat m;
    m.a[0][0]=1;m.a[0][2]=1;
    m.a[1][0]=1;
    m.a[2][1]=1;
    mat mp=qpow(m,n-2);
    cout<<mp.a[0][2]<<endl;
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
