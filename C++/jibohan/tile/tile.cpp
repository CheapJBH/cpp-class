#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const lnt MOD = 998244353;
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
const int N = 5005;
lnt fact[N], invf[N];
lnt C(int n, int k)
{
    if (k < 0 || k > n) return 0;
    return fact[n] % MOD * invf[k] % MOD * invf[n - k] % MOD;
}
lnt dp[N], ndp[N];
void Solve(void)
{
    string s;
    cin >> s;
    int n = s.size();
    int cnt[26] = {};
    for (char c : s) cnt[c - 'a']++;
    dp[0] = 1;
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] == 0) continue;
        int f = cnt[i];
        memset(ndp, 0, sizeof(ndp));
        for (int L = 0; L <= n; L++)
        {
            if (dp[L] == 0) continue;
            for (int c = 0; c <= f && L + c <= n; c++)
            {
                lnt val = invf[c];
                ndp[L + c] = (ndp[L + c] + dp[L] * val % MOD) % MOD;
            }
        }
        memcpy(dp, ndp, sizeof(ndp));
    }
    lnt ans = 0;
    for (int L = 1; L <= n; L++)
        ans = (ans + fact[L] * dp[L] % MOD) % MOD;
    cout << ans << endl;
}
/*====================*/
int main()
{
#ifndef ONLINE_JUDGE
    freopen("tile.in", "r", stdin);
    freopen("tile.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fact[0] = invf[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i % MOD;
    invf[N - 1] = power(fact[N - 1], MOD - 2, MOD);
    for (int i = N - 2; i >= 1; i--) invf[i] = invf[i + 1] * (i + 1) % MOD;
    int T = 1;
    while (T--)Solve();
    return 0;
}
