#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int n, a, b;
    cin >> n >> a >> b;
    if (a > b)          
    {
        cout << n + 1 + (a - b - 1);
    } else {
        cout << n - (b - a - 1);
    }
    
}