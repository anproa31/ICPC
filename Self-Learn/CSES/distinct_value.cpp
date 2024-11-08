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

    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    ll n;
    ll count = 0;
    cin >> n;

    vector<ll> x(n);
    for(ll i = 0; i < n; i++) {
        cin >> x[i];
    }

    sort(x.begin(), x.end());
    for (ll i = 0; i < n; i++)
    {
        if(x[i] != x[i + 1]) count++;
    }

    cout << count++;
    return 0;
}
