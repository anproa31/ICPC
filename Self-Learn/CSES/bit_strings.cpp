#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define MAX 1000000007

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int n;
    cin >> n;
    long long ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans = (ans * 2) % MAX;
    }

    cout << ans << endl;

    return 0;
}
