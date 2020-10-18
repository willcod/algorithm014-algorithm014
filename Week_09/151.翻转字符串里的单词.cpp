/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int n = s.length();
        int pos = 0;

        for (int left = 0; left < n; left++) {
            if (s[left] != ' ') {
                if (pos > 0) {
                    s[pos++] = ' ';
                }

                int right = left;
                while (right < n && s[right] != ' ') {
                    s[pos++] = s[right++];
                }
                reverse(s.begin() + pos - (right - left), s.begin() + pos);
                left = right;
            }
        }
        s.erase(s.begin() + pos, s.end());
        return s;
    }
};
// @lc code=end
