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

    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    int max = 0;
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] != s[i + 1]) {
            count = 0;
        }
        else {
            count++;
            if(count > max) {
                max = count;
            }
        }
    }
    cout << max + 1 << endl;

    return 0;
}
