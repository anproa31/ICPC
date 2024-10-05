#include <iostream>
#include <vector>

using namespace std;

void findCombination(vector<int> &denominations, int S)
{
    int n = denominations.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(S + 1, false));

    // Khởi tạo trường hợp cơ sở
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // Xây dựng bảng dp
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= S; j++)
        {
            if (j < denominations[i - 1])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - denominations[i - 1]];
        }
    }

    // Kiểm tra xem có tồn tại giải pháp hay không
    if (!dp[n][S])
    {
        cout << -1 << endl;
        return;
    }

    // Truy vết để tìm ra giải pháp
    vector<int> solution;
    int i = n, j = S;
    while (i > 0 && j > 0)
    {
        if (dp[i][j] != dp[i - 1][j])
        {
            solution.push_back(denominations[i - 1]);
            j -= denominations[i - 1];
        }
        i--;
    }

    // In ra giải pháp
    for (int i = 0; i < solution.size(); i++)
    {
        cout << solution[i] << " ";
    }
    cout << endl;
}

int main()
{
    freopen("input_3.txt", "r", stdin);
    freopen("output_3.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, S;
    cin >> n >> S;

    vector<int> denominations(n);

    for (int i = 0; i < n; i++)
        cin >> denominations[i];

    findCombination(denominations, S);

    return 0;
}