#include <string>
#include <vector>
//
// Created by antoe on 5/22/2024.
//
using namespace std;
class Solution {
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        dfs(s, 0, path, res);
        return res;
    }

private:
    void dfs(string& s, int start, vector<string>& path, vector<vector<string>>& res) {
        if (start == s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i - start + 1));
                dfs(s, i + 1, path, res);
                path.pop_back();
            }
        }
    }

    static bool isPalindrome(string& s, int l, int r) {
        while(l < r) {
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }
};
