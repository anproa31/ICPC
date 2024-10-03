#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;


int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, k;
    cin >> n >> k;
    cout << (n * 2) / (k + 2);

    return 0;
}

