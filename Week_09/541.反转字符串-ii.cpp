/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    string reverseStr(string s, int k) {
        int n = s.length();

        for (int i = 0; i < n; i += 2 * k) {
            if (i + k <= n) {
                reverse(s.begin() + i, s.begin() + i + k);
            } else {
                reverse(s.begin() + i, s.end());
            }
        }

        return s;
    }
};
// @lc code=end
