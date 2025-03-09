#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 15;
int n;
int s;
int col[MAX_N], diag1[2 * MAX_N], diag2[2 * MAX_N];

void search(int y)
{
    if (y == n)
    {
        s++;
        return;
    }
    for (int x = 0; x < n; x++)
    {
        if(col[x] || diag1[x + y] || diag2[x - y + n - 1]) continue;
        col[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;
        search(y + 1);
        col[x] = diag1[x + y] = diag2[x - y + n - 1] = 0;
    }
    
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int T;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cin >> n;
        s = 0;
        memset(col, 0, sizeof(col));
        memset(diag1, 0, sizeof(diag1));
        memset(diag2, 0, sizeof(diag2));

        search(0);
        cout << "#" << i << ": "<< s << endl;
    }

    return 0;
}
