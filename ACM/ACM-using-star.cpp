#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    // Add a boundary of '*' around the matrix
    vector<string> bg(m + 2, string(n + 2, '*'));
    
    for(int i = 1; i <= m; i++) {
        string row;
        cin >> row;
        bg[i] = "*" + row + "*";  // Add '*' to the beginning and end of each row
    }

    int ans = 0;

    // Directions for checking (up, down, left, right)
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    // Function to check for ACM pattern around 'C'
    auto check_acm = [&](int i, int j) {
        int ca = 0, cm = 0;
        for (int d = 0; d < 4; d++) {
            int ni = i + dx[d], nj = j + dy[d];
            if (bg[ni][nj] == 'A') ca++;
            if (bg[ni][nj] == 'M') cm++;
        }
        return ca * cm;  // Return the count of valid ACM patterns found
    };

    // Loop through the matrix and find 'C'
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (bg[i][j] == 'C') {
                ans += check_acm(i, j);
            }
        }
    }

    cout << ans;

    return 0;
}
