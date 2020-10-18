/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) return s;

        int min_left = 0;
        int max_right = s.length() - 1;
        int max_len = 0;

        for (int mid = 0; mid < s.length();) {
            int left = mid;
            int right = mid;

            while (right < max_right && s[right] == s[right + 1]) right++;
            mid = right + 1;

            while (right < max_right && left > 0 &&
                   s[left - 1] == s[right + 1]) {
                left--;
                right++;
            }

            int new_len = right - left + 1;
            if (new_len > max_len) {
                max_len = new_len;
                min_left = left;
            }
        }

        return s.substr(min_left, max_len);
    }
};
// @lc code=end
