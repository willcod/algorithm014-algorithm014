/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    bool isMatch(string s, string p) {
        int n = p.length();

        int i = 0, j = 0, star = -1, match = 0;

        while (i < s.length()) {
            if (j < n && (s[i] == p[j] || p[j] == '?')) {
                i++;
                j++;
            } else if (j < n && p[j] == '*') {
                match = i;
                star = j++;
            } else if (star >= 0) {
                i = ++match;
                j = star + 1;
            } else {
                return false;
            }
        }

        while (j < n && p[j] == '*') j++;
        return j == n;
    }
};
// @lc code=end
