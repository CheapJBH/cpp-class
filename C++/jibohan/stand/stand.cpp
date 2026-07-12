#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
void Solve(void)
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<pair<int, int>> groups;
    for (int i = 0; i < n; )
    {
        if (s[i] == '0')
        {
            int j = i;
            while (j < n && s[j] == '0') j++;
            groups.push_back({i, j - 1});
            i = j;
        }
        else i++;
    }
    int m = groups.size();
    if (m == 0 || k >= m)
    {
        cout << n << endl;
        return;
    }
    int ans = 0;
    int mx = groups[0].first;
    for (int i = 1; i < m; i++)
        mx = max(mx, groups[i].first - groups[i - 1].second - 1);
    mx = max(mx, n - groups[m - 1].second - 1);
    ans = mx;
    if (k > 0)
    {
        for (int i = 0; i + k - 1 < m; i++)
        {
            int j = i + k - 1;
            int L = (i > 0) ? groups[i - 1].second + 1 : 0;
            int R = (j < m - 1) ? groups[j + 1].first - 1 : n - 1;
            ans = max(ans, R - L + 1);
        }
    }
    cout << ans << endl;
}
/*====================*/
int main()
{
#ifndef ONLINE_JUDGE
    freopen("stand.in", "r", stdin);
    freopen("stand.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--)Solve();
    return 0;
}
