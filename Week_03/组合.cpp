/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    if (n <= 0 || k <= 0 || k > n) return {};

    vector<vector<int>> result;
    vector<int> sub;
    backtracking(result, n, k, sub, 1);
    return result;
  }

  void backtracking(vector<vector<int>>& result, int n, int k, vector<int>& sub,
                    int index) {
    if (sub.size() == k) {
      result.push_back(sub);
      return;
    }

    for (int i = index; i <=n; i++) { //i <= n - (k - sub.size()) + 1 剪枝
      sub.push_back(i);
      backtracking(result, n, k, sub, i + 1);
      sub.pop_back();
    }
  }
};
// @lc code=end
