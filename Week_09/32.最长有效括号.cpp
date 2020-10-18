/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int longestValidParentheses(string s) {
        int n = s.length();

        int maxlen = 0;

        vector f(n + 1, 0);
        for (int i = 1; i < n; i++) {
            if (s[i] == ')' && i - f[i] && s[i - f[i] - 1] == '(') {
                f[i + 1] = f[i] + f[i - f[i] - 1] + 2;
            }

            maxlen = max(maxlen, f[i + 1]);
        }

        return maxlen;
    }
};
// @lc code=end
