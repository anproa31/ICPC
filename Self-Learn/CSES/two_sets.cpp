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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    ll sum = n * (n + 1) / 2;
    if (sum % 2)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    vi a, b;
    sum /= 2;   
    while (n)
    {
        if (sum - n >= 0)
        {
            a.push_back(n);
            sum -= n;
        }
        else
        {
            b.push_back(n);
        }
        n--;
    }

    cout << a.size() << endl;
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << b.size() << endl;
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }

    return 0;
}
