#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Matrix3D {
private:
    vector<vector<vector<int>>> data;
    int size;

public:
    Matrix3D(int n) : size(n) {
        data.resize(n, vector<vector<int>>(n, vector<int>(n, 0)));
    }

    void update(int x, int y, int z, int W) {
        data[x-1][y-1][z-1] += W;  // Add W to the existing value
    }

    int query(int x1, int y1, int z1, int x2, int y2, int z2) {
        int sum = 0;
        for (int x = x1-1; x < x2; x++) {
            for (int y = y1-1; y < y2; y++) {
                for (int z = z1-1; z < z2; z++) {
                    sum += data[x][y][z];
                }
            }
        }
        return sum;
    }
};

int main() {
    int T;
    cin >> T;

    vector<int> results;  // Store all results from all test cases

    while (T--) {
        int n, m;
        cin >> n >> m;

        Matrix3D matrix(n);

        for (int i = 0; i < m; i++) {
            string operation;
            cin >> operation;

            if (operation == "UPDATE") {
                int x, y, z, W;
                cin >> x >> y >> z >> W;
                matrix.update(x, y, z, W);
            } else if (operation == "QUERY") {
                int x1, y1, z1, x2, y2, z2;
                cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
                results.push_back(matrix.query(x1, y1, z1, x2, y2, z2));
            }
        }
    }

    // Print all results at the end
    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}
