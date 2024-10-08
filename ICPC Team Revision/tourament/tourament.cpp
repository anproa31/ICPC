#include <bits/stdc++.h>

using namespace std;
#define fastInp                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
class SegmentTree
{
private:
    vector<int> tree;
    int n;

public:
    // Hàm khởi tạo cây đoạn
    SegmentTree(const vector<int> &data)
    {
        n = data.size();
        tree.resize(2 * n);

        // Xây dựng cây bằng cách thêm mảng dữ liệu vào vị trí lá
        for (int i = 0; i < n; i++)
        {
            tree[n + i] = data[i];
        }

        // Xây dựng cây bằng cách tính giá trị cha từ giá trị con
        for (int i = n - 1; i > 0; --i)
        {
            tree[i] = min(tree[2 * i], tree[2 * i + 1]);
        }
    }

    // Hàm query để tìm giá trị nhỏ nhất trong đoạn [l, r)
    int query(int l, int r)
    {
        int res = INT_MAX;
        l += n;
        r += n;

        while (l < r)
        {
            if (l % 2 == 1)
            {
                res = min(res, tree[l]);
                l++;
            }
            if (r % 2 == 1)
            {
                r--;
                res = min(res, tree[r]);
            }
            l /= 2;
            r /= 2;
        }
        return res;
    }
};

int min_pair_difference(vector<int> &arr)
{
    int n = arr.size();
    if (n < 2)
        return 0;

    // Bước 1: Sắp xếp mảng năng lực
    sort(arr.begin(), arr.end());

    // Bước 2: Xây dựng Segment Tree với dữ liệu đã sắp xếp
    SegmentTree segTree(arr);

    // Bước 3: Tìm sự chênh lệch nhỏ nhất giữa các phần tử liên tiếp
    int min_diff = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        min_diff = min(min_diff, arr[i] - arr[i - 1]);
    }

    return min_diff;
}

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    fastInp;
    // Dữ liệu đầu vào
    int n;
    cin >> n; // Số lượng học sinh
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Chỉ số năng lực của từng học sinh
    }

    // Gọi hàm tính chênh lệch nhỏ nhất
    int result = min_pair_difference(arr);

    // In ra kết quả
    cout << result << endl;

    return 0;
}
