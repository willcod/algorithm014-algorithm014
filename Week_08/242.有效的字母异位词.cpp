/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> stat;
        for(int i = 0; i < s.length(); i++) {
            stat[s[i]]++;
            stat[t[i]]--;
        }

        for (auto kv : stat) {
            if (kv.second != 0) {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

