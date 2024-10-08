#include <bits/stdc++.h>
using namespace std;

int n, p, k, q;
vector<int64_t> a;
int64_t ans = 0, x;

void upd(int i, int64_t val)
{
    int u = p + i;
    a[u] = val;
    u >>= 1;
    while (u > 0)
    {
        a[u] = __gcd(a[u << 1], a[u << 1 | 1]);
        u >>= 1;
    }
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    p = 1;
    while (p < k)
        p <<= 1;
    a.assign(4 * p + 5, 0);
    for (int i = 0; i < k; i++)
    {
        cin >> a[p + i];
    }
    for (int i = p - 1; i > 0; i--)
    {
        __gcd(a[i << 1], a[i << 1 | 1]);
    }

    ans = a[1];
    for (int i = k; i < n; i++)
    {
        cin >> x;
        upd(i % k, x);
        if (ans < a[1])
        {
            ans = a[1];
        }
    }

    cout << ans << "\n";
    
}