/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        vector<int> minNums;
        for (int n : nums) {
            if (minNums.empty() || n > minNums.back()) {
                minNums.push_back(n);
            } else {
                *lower_bound(minNums.begin(), minNums.end(), n) = n;
            }
        }
        return minNums.size();
    }
};
// @lc code=end
// O(n^2)
class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        int n = nums.size();

        vector f(n, 1);
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
        }

        return *max_element(f.begin(), f.end());
    }
};