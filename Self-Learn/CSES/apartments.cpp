#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
const ll MAX = 2e5 + 7;

ll n, m, k, a[MAX], b[MAX], ans;

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];

    sort(a, a + n);
    sort(b, b + m);
    ll i = 0, j = 0;
    while (i < n && j < m)
    {
        if (abs(a[i] - b[j]) <= k)
        {
            j++;
            i++;
            ans++;
        }
        else
        {
            if (a[i] - b[j] > k)
            {
                j++;
            }
            else
            {
                i++;
            }
        }
    }
    cout << ans;
    return 0;
}
