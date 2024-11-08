#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
const ll MAX = 2e5 + 1;

ll n, x, p[MAX], ans;
bool have_gondola_yet[MAX];

int main()
{
    cin >> n >> x;
    for (ll i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    sort(p, p + n);
    ll i = 0, j = n - 1;

    while (i < j)
    {
        if (p[i] + p[j] > x)
        {
            // If the total weight of two children exceeds x
            // Then we move to the lighter child.
            --j;
        }
        else
        {          // If it satisfies the condition.
            ++ans; // Increment the number of gondolas used
            // Mark that they have had their gondola
            have_gondola_yet[i] = have_gondola_yet[j] = true;
            ++i;
            --j; // Move to the next children.
        }
    }
    for (int i = 0; i < n; ++i)
    {
        // Calculate the number of children not having gondolas yet
        // to get the total number of gondolas needed for the problem.
        ans += (have_gondola_yet[i] == false);
    }
    cout << ans;
    return 0;
}
