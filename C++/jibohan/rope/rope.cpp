#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
void Solve(void)
{
    int n;
    lnt k;
    cin >> n >> k;
    vector<lnt> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    lnt lo = 1, hi = *max_element(a.begin(), a.end());
    while (lo < hi)
    {
        lnt mid = (lo + hi) / 2;
        lnt cuts = 0;
        for (int i = 0; i < n; i++)
        {
            cuts += (a[i] - 1) / mid;
            if (cuts > k) break;
        }
        if (cuts <= k) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << endl;
}
/*====================*/
int main()
{
#ifndef ONLINE_JUDGE
    freopen("rope.in", "r", stdin);
    freopen("rope.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--)Solve();
    return 0;
}
