#include <iostream>
#include <vector>
#include <algorithm>

void generateSubsets(std::vector<int> &nums, int testCaseNum) {
    int n = nums.size();
    std::vector<std::vector<int>> subsets;


    int totalSubsets = 1 << n;
    for (int mask = 1; mask < totalSubsets; ++mask) {
        std::vector<int> subset;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                subset.push_back(nums[i]);
            }
        }
        subsets.push_back(subset);
    }

    std::sort(subsets.begin(), subsets.end());

    std::cout << "#"<< testCaseNum << ":\n";
    for (size_t i = 0; i < subsets.size(); ++i) {
        std::cout << i + 1 << ":";
        for (size_t j = 0; j < subsets[i].size(); ++j) {
            std::cout << " " << subsets[i][j];
        }
        std::cout << "\n";
    }
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    std::cin >> T;


    for (int t = 1; t <= T; ++t) {
        int N;
        std::cin >> N;
        std::vector<int> nums(N);
        
        for (int i = 0; i < N; ++i) {
            std::cin >> nums[i];
        }

 
        std::sort(nums.begin(), nums.end());

        generateSubsets(nums, t);
    }

    return 0;
}
