#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define MAX 1e9 + 7

ll minDiff(vector<ll> &p, int idx, ll sum1, ll total)
{

    if (idx < 0)
    {
        return abs(total - 2 * sum1);
    }

    ll include = minDiff(p, idx - 1, sum1 + p[idx], total);
    ll exclude = minDiff(p, idx - 1, sum1, total);

    return min(include, exclude);
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll n;
    cin >> n;
    ll total = 0;
    vector<ll> p(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> p[i];
        total += p[i];
    }

    cout << minDiff(p, n - 1, 0, total);

    return 0;
}
