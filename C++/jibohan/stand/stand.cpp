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
    vector<pair<int, int>> blocks;
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1]) cnt++;
        else { blocks.push_back({s[i - 1] - '0', cnt}); cnt = 1; }
    }
    blocks.push_back({s[n - 1] - '0', cnt});
    int m = blocks.size(), ans = 0;
    int l = 0, zeros = 0, len = 0;
    for (int r = 0; r < m; r++)
    {
        len += blocks[r].second;
        if (blocks[r].first == 0) zeros++;
        while (zeros > k)
        {
            len -= blocks[l].second;
            if (blocks[l].first == 0) zeros--;
            l++;
        }
        ans = max(ans, len);
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
