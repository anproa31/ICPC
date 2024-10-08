#include <bits/stdc++.h>
using namespace std;
int64_t solve(int64_t n, int64_t m, int64_t h, int64_t w)
{
    int64_t ans = 0;
    while (h < n) {ans++, h <<= 1;}
    while (w < m) {ans++, w <<= 1;}


    return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int64_t n, m, h, w;
    cin >> n >> m >> h >> w;

    cout << min(solve(n, m, h, w), solve(m, n, h, w));

}