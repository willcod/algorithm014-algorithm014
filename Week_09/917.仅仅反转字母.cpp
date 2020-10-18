/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    string reverseOnlyLetters(string S) {
        //双指针，跳过非字母，
        int left = 0;
        int right = S.length() - 1;

        while (left < right) {
            if (!isalpha(S[left])) left++;
            if (!isalpha(S[right])) right--;

            if (isalpha(S[left]) && isalpha(S[right])) {
                swap(S[left++], S[right--]);
            }
        }
        return S;
    }
};
// @lc code=end
