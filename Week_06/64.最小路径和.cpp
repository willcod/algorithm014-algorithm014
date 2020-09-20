/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i == 0 && j == 0) continue;
        if (i == 0)
          grid[i][j] = grid[i][j - 1] + grid[i][j];
        else if (j == 0)
          grid[i][j] = grid[i - 1][j] + grid[i][j];
        else
          grid[i][j] =
              min(grid[i - 1][j] + grid[i][j], grid[i][j - 1] + grid[i][j]);
      }
    }

    return grid[n - 1][m - 1];
  }
};
// @lc code=end
