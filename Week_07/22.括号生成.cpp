/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> result;
    addParen(result, "", n, 0);
    return result;
  }

  void addParen(vector<string>& result, string str, int left, int right) {
    if (left == 0 && right == 0) {
      result.push_back(str);
    }

    if (left > 0) addParen(result, str + "(", left - 1, right + 1);
    if (right > 0) addParen(result, str + ")", left, right - 1);
  }
};
// @lc code=end
