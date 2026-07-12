#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
void Solve(void)
{
    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    for (int i = 0; i < h; i++) cin >> g[i];
    vector<bool> row(h, false), col(w, false);
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (g[i][j] == '#') row[i] = col[j] = true;
    for (int i = 0; i < h; i++)
    {
        if (!row[i]) continue;
        for (int j = 0; j < w; j++)
            if (col[j]) cout << g[i][j];
        cout << endl;
    }
}
/*====================*/
int main()
{
#ifndef ONLINE_JUDGE
    // freopen("poster.in", "r", stdin);
    // freopen("poster.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--)Solve();
    return 0;
}
