#include <iostream>
#include <vector>

using namespace std;

const int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int N, totalWays;
vector<vector<int> > board;

bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N && board[x][y] == 0;
}

void knightTour(int step, int x, int y) {
    board[x][y] = step;

    if (step == N * N) {
        totalWays++;
        board[x][y] = 0;
        return;
    }

    for (int k = 0; k < 8; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (isValid(nx, ny)) {
            knightTour(step + 1, nx, ny);
        }
    }

    board[x][y] = 0;
}

void solve(int testCase) {
    int x, y;
    cin >> N >> x >> y;
    x--, y--;

    totalWays = 0;
    board.assign(N, vector<int>(N, 0));

    knightTour(1, x, y);

    cout << "#" << testCase << ": ";
    if (totalWays > 0) {
        cout << "1 " << totalWays << "\n";
    } else {
        cout << "0\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(i);
    }
    return 0;
}
