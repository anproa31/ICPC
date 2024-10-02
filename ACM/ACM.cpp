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

    vector<string> bg(m);
    for(auto &x:bg) {
        cin >> x;
    }

    int ans = 0, ca, cm;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(bg[i][j] == 'C') {
                ca = cm = 0;
                if(i - 1 >= 0) {
                    if(bg[i - 1][j] == 'A') {
                        ca++;
                    } else if(bg[i - 1][j] == 'M') {
                        cm++;
                    }
                }
                if(i + 1 < m) {
                    if(bg[i + 1][j] == 'A') {
                        ca++;
                    } else if(bg[i + 1][j] == 'M') {
                        cm++;
                    }
                }

                if(j - 1 >= 0) {
                    if(bg[i][j - 1] == 'A') {
                        ca++;
                    } else if(bg[i][j - 1] == 'M') {
                        cm++;
                    }
                }
                if(j + 1 < n) {
                    if(bg[i][j + 1] == 'A') {
                        ca++;
                    } else if(bg[i][j + 1] == 'M') {
                        cm++;
                    }
                }

                ans += ca * cm;
            }
        }
    }

    cout << ans;

    return 0;
}

//fix this solution using * cover the matrix m*n