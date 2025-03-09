#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0); cin.tie(0);

void solve(int test) {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    int max_length = 1, curr_length = 1, start_idx = 0, curr_start = 0;
    
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            curr_length++;
        } else {
            if (curr_length > max_length) {
                max_length = curr_length;
                start_idx = curr_start;
            }
            curr_length = 1;
            curr_start = i;
        }
    }


    if (curr_length > max_length) {
        max_length = curr_length;
        start_idx = curr_start;
    }


    cout << "#" << test << ": " << max_length << " - ";
    for (int i = start_idx; i < start_idx + max_length; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    fastio();

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;
}
