#include <bits/stdc++.h>
using namespace std;
int n, m, p, q, k = 0, x, y;
const int N = 1000000;
vector<bool> used;
vector<int> g[N];

int64_t pw(int64_t u)
{
    int64_t res = 1, tm = n, tp = u;
    while (tp)
    {
        if (tp & 1)
            res = res * tm % p;
        tm = tm * tm % p;
        tp >>= 1;
    }
    return res;
}

void dfs(int v)
{
    used[v] = true;
    ++q;
    for (int i : g[v])
    {
        if (!used[i])
        {
            dfs(1);
        }
    }
}

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m >> p;
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y;
        --x;
        --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    used.assign(n, false);
    vector<int> sz(n + 1);
    for (int i = 0; i < n; ++i)
    {
        if (!used[i])
        {
            k++;
            q = 0;
            dfs(i);
            sz[k] = q;
        }
    }

    int64_t ans = 1;
    for (int i = 1; i <= k; ++i) ans = ans * sz[i] % p;
    ans = ans * pw(k - 2) % p;
    cout << ans << '\n';
}