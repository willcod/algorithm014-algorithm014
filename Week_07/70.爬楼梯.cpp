/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
 public:
  int climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    int oneStep = 2;
    int twoStep = 1;
    int allStep = 0;

    for (int i = 3; i <= n; i++) {
      allStep = oneStep + twoStep;
      twoStep = oneStep;
      oneStep = allStep;
    }

    return allStep;
  }
};
// @lc code=end
