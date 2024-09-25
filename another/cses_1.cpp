//
// Created by antoe on 8/17/2024.
//
#include<bits/stdc++.h>
using namespace std;

// long long cses_1(long long n) {
//     cout << n << " ";
//     while( n != 1) {
//         if(n % 2 == 0) {
//             n = n / 2;
//             cout << n << " ";
//         } else {
//             n = n * 3 + 1;
//             cout << n << " ";
//         }
//     }
//     return n;
// }

// long long cses_2(long long n, long long arr[]) {
//     long long s = n * (n + 1) / 2;
//     long long sum = 0;
//     for(int i = 0; i < n - 1; i++) {
//         sum += arr[i];
//     }
//     return s - sum;
// }

// int cses_3(string s) {
//     char curr;
//     int count = 0, ans = 0;
//     for(int i = 0; i < s.length(); i++) {
//         if(s[i] == curr) {
//             count++;
//         }
//         if(s[i] != curr) {
//             curr = s[i];
//             count = 1;
//         }
//         ans = max(ans, count);
//     }
//     return ans;
// }
long long cses_4(long long n, long long arr[]) {
    long long count = 0;
    for(int i = 1; i < n; i++) {
        if(arr[i] < arr[i - 1]) {
            count += (arr[i - 1] - arr[i]);
            arr[i] = arr[i - 1];
        }
    }
    return count;
}


int main() {
    long long n;
    cin >> n;
    long long arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << cses_4(n, arr) << endl;
}