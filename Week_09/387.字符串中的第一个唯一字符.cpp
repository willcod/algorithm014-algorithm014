/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int firstUniqChar(string s) {
        int count[26] = {0};
        for (char c : s) {
            count[c - 'a']++;
        }

        for (int i = 0; i < s.length(); i++) {
            if (count[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};
// @lc code=end
