#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define MOD 1000000007
#define MAX 1000001

ll DP[MAX], n;

ll compute(int left)
{
    if (DP[left] != 0)
    {
        return DP[left];
    }
    for (int i = 1; i <= 6; i++)
    {
        if (left - i >= 0)
        {
            DP[left] += compute(left - i);
            DP[left] %= MOD;
        }
    }
    return DP[left];
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    memset(DP, 0, sizeof(DP));
    DP[0] = 1;
    cout << compute(n) << endl;

    return 0;
}
