/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    bool isIsomorphic(string s, string t) {
        if (s == t) return true;
        if (s.length() != t.length()) return false;

        for (int i = 0; i < s.length(); i++) {
            if (s.find(s[i]) != t.find(t[i])) return false;
        }
        return true;
    }
};
// @lc code=end
