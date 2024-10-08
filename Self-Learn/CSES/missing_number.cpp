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
    long long x;
    cin >> n;
    int sum = n * (n + 1) / 2;
    while (cin >> x) {
        sum -= x;
    }
    cout << sum << endl;   

    return 0;
}
