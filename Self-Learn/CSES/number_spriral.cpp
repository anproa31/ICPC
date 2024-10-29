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

    ll t;
    cin >> t;
    while(t--) {
        ll x, y;
        cin >> x >> y;
        ll z = max(x, y);
        ll z2 = z * z;
        if(z % 2 == 0) {
            if(z == x) {
                cout << z2 - y + 1 << endl;
            }
            else {
                cout << z2 - 2 * z + x + 1 << endl;
            }
        }
        else {
            if(z == x) {
                cout << z2 - 2 * z + y + 1 << endl;
            }
            else {
                cout << z2 - x + 1 << endl;
            }
        }
    }
    return 0;
}
