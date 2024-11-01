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
;

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    ll ans = 0;
    for(ll i = 5; n / i >= 1; i *= 5) {
        ans += n / i;
    }

    cout << ans;
   
    return 0;
}
