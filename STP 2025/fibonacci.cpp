#include <iostream>
#include <vector>
using namespace std;

int t, n;


long long fibonacci(int n, vector<long long> &memo) {
    if(n <= 1) return n;
    if(memo[n] != -1) return memo[n];

    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    return memo[n];
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;
        vector<long long> memo(n + 1, -1);
        cout << fibonacci(n, memo) << endl;
    }

    return 0;
}
