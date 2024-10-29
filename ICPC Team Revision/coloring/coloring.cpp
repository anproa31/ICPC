#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define F first
#define S second
#define MAX 1e9 + 7

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vi a(n);
    vi p(q), k(q);
    for (int &i : a)
    {
        cin >> a[i];
    }

    for(int i = 0; i < q; ++i) {
        cin >> p[i] >> k[i];
    } 
    return 0;
}
