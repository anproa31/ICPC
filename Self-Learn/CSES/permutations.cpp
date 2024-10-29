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

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if(n <= 3 && n > 1) {
        cout << "NO SOLUTION" << endl;
    }
    else {
        for(int i = 2; i <= n; i += 2) {
            cout << i << " ";
        }
        for(int i = 1; i <= n; i += 2) {
            cout << i << " ";
        }
    }
    return 0;
}
