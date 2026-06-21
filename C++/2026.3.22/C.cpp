#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e3+5;
int f[maxn][maxn];
int g;
string a,b;

signed main()
{
    cin>>g;
    for(int k=1;k<=g;k++)
    {
        memset(f,0,sizeof(f));
        cin>>a>>b;
        int n=a.size(),m=b.size();
        a=" "+a,b=" "+b;    
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i]==b[j]) f[i][j]=f[i-1][j-1]+1;
                else f[i][j]=max(f[i-1][j],f[i][j-1]);
                
            }
        }
        cout<<f[n][m]<<endl;
    }
    return 0;
    
}
