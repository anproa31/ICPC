#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define ff first
#define ss second

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); 
    cin.tie(0);                   
    cout.tie(0);

    int n, m, r1 = 0, r2 = 0, t, k = 1, p, q;
    cin >> n >> m;

    // Ensure k is the smallest power of 2 greater than or equal to n
    while (k < n)
        k <<= 1;

    vector<pii> a(2 * k, {0, 0}), b(2 * k, {0, 0});

    for (int i = 0; i < n; i++)
    {
        cin >> t;
        a[i + k] = {t, k + i};
    }
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        b[k + i] = {t, i + k};
    }

    for (int i = k - 1; i > 0; --i)
    {
        if (a[2 * i].ff > a[2 * i + 1].ff)
            a[i] = a[2 * i];
        else
            a[i] = a[2 * i + 1];

        if (b[2 * i].ff > b[2 * i + 1].ff)
            b[i] = b[2 * i];
        else
            b[i] = b[2 * i + 1];
    }

    auto get_max = [&](vector<pii> &z, int u, int v)
    {
        pii x, y;
        u += k - 1;
        v += k - 1;
        x = z[u];
        y = z[v];
        while (v - u > 1)
        {
            if (u % 2 == 0)
                x = max(x, z[u + 1]);
            if (v % 2 == 1)
                y = max(z[v - 1], y);
            u >>= 1;
            v >>= 1;
        }
        return max(x, y);
    };

    pii t1, t2, t3, t4;
    int kq1, kq2, ra, rb;
    for (int i = 0; i < m; i++)
    {
        cin >> p >> q;
        if (q - p == 1)
        {
            kq1 = a[k + p - 1].ff + a[k + p].ff;
            kq2 = b[k + p - 1].ff + b[k + p].ff;
            if (kq1 > kq2)
                r1++;
            else if (kq1 < kq2)
                r2++;
            continue;
        }
        t1 = get_max(a, p, q);
        if (t1.ss == p - 1)
            t2 = get_max(a, p + 1, q);
        else if (t1.ss == q - 1)
            t2 = get_max(a, p, q - 1);
        else
        {
            t3 = get_max(a, p, t1.ss);
            t4 = get_max(a, t1.ss + 2, q);
        }

        ra = t3.ff + t4.ff;

        t1 = get_max(b, p, q);
        if (t1.ss == p - 1)
            t2 = get_max(b, p + 1, q);
        else if (t1.ss == q - 1)
            t2 = get_max(b, p, q - 1);
        else
        {
            t3 = get_max(b, p, t1.ss);
            t4 = get_max(b, t1.ss + 2, q);
        }

        rb = t3.ff + t4.ff;
        if (ra > rb)
            r1++;
        else if (ra < rb)
            r2++;
    }

    cout << r1 << ' ' << r2;
    cout << "\nTime: " << clock() / (double)1000 << " sec";
}
