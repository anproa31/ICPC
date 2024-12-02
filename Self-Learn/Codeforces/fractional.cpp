#include <bits/stdc++.h>
using namespace std;
const int64_t INF = 1'000'000;

int main()
{
    uint64_t n, c, b = 1;
    cin >> n >> c;
    while (n--)
    {
        b *= 10;
    }

    while (c % 5 == 0 && b % 5 == 0)
    {
        c /= 5;
        b /= 5;
    }

    while (c % 2 == 0 && b % 2 == 0)
    {
        c /= 2;
        b /= 2;
    }

    if(c < INF && b < INF && c > 0) cout << "YES";
    else cout << "NO";

    return 0;
}
