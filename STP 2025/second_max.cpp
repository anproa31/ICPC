#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long

void solve(int test) {
    int n;
    cin >> n;

    int first_max = INT_MIN, second_max = INT_MIN;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x > first_max) {
            second_max = first_max;
            first_max = x;
        } else if (x > second_max && x < first_max) {
            second_max = x;
        }
    }

    //rbegin()

    if (second_max == INT_MIN) second_max = first_max; // If no second max exists

    cout << "#" << test << " " << second_max << "\n";
}

int main() {
    // fastio();
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;
}
