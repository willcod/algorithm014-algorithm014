/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            } else {
                return isValid(s, left, right - 1) ||
                       isValid(s, left + 1, right);
            }
        }

        return true;
    }

    bool isValid(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;

            left++;
            right--;
        }
        return true;
    }
};
// @lc code=end
