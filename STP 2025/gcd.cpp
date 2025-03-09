#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    // fastio();

    


        ll a, b;
        cin >> a >> b;
        cout << gcd(a, b);
    return 0;
}
