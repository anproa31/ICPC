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
    int n;
    cin >> n;
    long long ways = 0;
    for (int i = 1; i <= n; i++)
    {
        ways = (long long)i * i * (i * i - 1) / 2 - 4 * (i - 1) * (i - 2);
        cout << ways << endl;
        ways = 0;
    }
    

    return 0;
}
