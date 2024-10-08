#include <bits/stdc++.h>
using namespace std;
int a[1000001];

int main()
{
    freopen("input_2.txt", "r", stdin);
    freopen("output_2.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int c;
    int sum = 0;
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);
    for(int i = 0; i < n; i++) {
        if(sum <= c) {
            sum += a[i];
            cout << a[i] << endl;
        }
    }
    return 0;

}