#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define t128 __int128_t

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    ll n, m;
    t128 ans;
    for(int i = 0; i < t; i++) {
        cin >> n >> m;
        if(n > m) swap(n, m);
        ans = (t128)n *(n+1)*(3*m-n+1)/6;
        string s = "";
        while(ans) {
            s = char (ans%10 + 48) + s;
            ans /= 10;
        }
        cout << s << "\n";
    }
}