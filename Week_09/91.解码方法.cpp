/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int numDecodings(string s) {
        int n = s.length();

        vector f(n+1, 0);
        f[n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                f[i] = 0;
            } else {
                f[i] = f[i + 1];
                if (i < n - 1 &&
                    (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6')) {
                    f[i] += f[i + 2];
                }
            }
        }
        return f[0];
    }
};
// @lc code=end
