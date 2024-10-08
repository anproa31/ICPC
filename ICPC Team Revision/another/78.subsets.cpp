/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution_BackTracking {
public:
 vector<vector<int>> subsets(vector<int>& nums) {
  vector<vector<int>> subs;
  vector<int> sub;
  subsets(nums, 0, sub, subs);
  return subs;
 }
private:
 void subsets(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& subs) {
  subs.push_back(sub);
  for (int j = i; j < nums.size(); j++) {
   sub.push_back(nums[j]);
   subsets(nums, j + 1, sub, subs);
   sub.pop_back();
  }
 }
};

class Solution_Iteration {
public:
 vector<vector<int>> subsets(vector<int>& nums) {
  vector<vector<int>> subs = {{}};
  for (int num : nums) {
   int n = subs.size();
   for (int i = 0; i < n; i++) {
    subs.push_back(subs[i]);
    subs.back().push_back(num);
   }
  }
  return subs;
 }
};

class Solution_Bit_manipulation {
public:
 vector<vector<int>> subsets(vector<int>& nums) {
  int n = nums.size(), p = 1 << n;
  vector<vector<int>> subs(p);
  for (int i = 0; i < p; i++) {
   for (int j = 0; j < n; j++) {
    if ((i >> j) & 1) {
     subs[i].push_back(nums[j]);
    }
   }
  }
  return subs;
 }
};
