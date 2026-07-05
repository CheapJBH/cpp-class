#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
using lnt = long long;
/*====================*/
const int N = 5e5 + 10;
/*====================*/
int n, arr[N];
/*====================*/
int tmp[N];
lnt Calc(int l, int r)
{
    if (l == r)return 0;
    int mid = (l + r) >> 1;
    lnt res = Calc(l, mid) + Calc(mid + 1, r);
    int i = l, j = mid + 1, p = l;
    while (i <= mid && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            tmp[p++] = arr[i++];
        }
        else
        {
            res += mid - i + 1;
            tmp[p++] = arr[j++];
        }
    }
    while (i <= mid)tmp[p++] = arr[i++];
    while (j <= r)  tmp[p++] = arr[j++];
    for (int i = l;i <= r;++i)arr[i] = tmp[i];
    return res;
}
/*====================*/
/*====================*/
void Solve(void)
{
    cin >> n;
    for (int i = 1;i <= n;++i)
    {
        cin >> arr[i];
    }
    cout << Calc(1, n) << endl;
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