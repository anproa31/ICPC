#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define MAX 1e9 + 7

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    long long ans = 0;
    cin >> n;
    vector<long long> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            if (a[i - 1] > a[i])
            {
                ans += a[i - 1] - a[i];
                a[i] = a[i - 1];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
