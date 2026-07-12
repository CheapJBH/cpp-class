#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const lnt MOD = 1e9 + 7;
lnt power(lnt a, lnt b, lnt mod)
{
    lnt res = 1;
    a %= mod;
    while (b > 0)
    {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void Solve(void)
{
    string s;
    cin >> s;
    int n = s.size();
    lnt inv3 = power(3, MOD - 2, MOD);
    lnt q = 0;
    for (char c : s) if (c == '?') q++;
    vector<lnt> pre(n, 0), suf(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (i > 0) pre[i] = pre[i - 1];
        if (s[i] == 'A') pre[i] = (pre[i] + 1) % MOD;
        else if (s[i] == '?') pre[i] = (pre[i] + inv3) % MOD;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (i < n - 1) suf[i] = suf[i + 1];
        if (s[i] == 'C') suf[i] = (suf[i] + 1) % MOD;
        else if (s[i] == '?') suf[i] = (suf[i] + inv3) % MOD;
    }
    lnt ans = 0;
    for (int j = 0; j < n; j++)
    {
        if (s[j] != 'B' && s[j] != '?') continue;
        lnt w = (s[j] == 'B') ? 1 : inv3;
        lnt pa = (j > 0) ? pre[j - 1] : 0;
        lnt sc = (j < n - 1) ? suf[j + 1] : 0;
        ans = (ans + w * pa % MOD * sc % MOD) % MOD;
    }
    ans = ans * power(3, q, MOD) % MOD;
    cout << ans << endl;
}
/*====================*/
int main()
{
#ifndef ONLINE_JUDGE
    freopen("system.in", "r", stdin);
    freopen("system.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--)Solve();
    return 0;
}
