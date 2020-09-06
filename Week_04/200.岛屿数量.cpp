/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    int w = grid.size();
    int h = w ? grid[0].size() : 0;

    if (w == 0 && h == 0) return 0;

    int count = 0;
    for (int i = 0; i < w; i++) {
      for (int j = 0; j < h; j++) {
        if (grid[i][j] == '1') {
          count++;
          eraseIsland(grid, i, j);
        }
      }
    }

    return count;
  }

  void eraseIsland(vector<vector<char>>& grid, int x, int y) {
    if (!isValid(grid, x, y)) return;

    if (grid[x][y] == '1') {
      grid[x][y] = '0';

      eraseIsland(grid, x + 1, y);
      eraseIsland(grid, x - 1, y);
      eraseIsland(grid, x, y + 1);
      eraseIsland(grid, x, y - 1);
    }
  }

  bool isValid(vector<vector<char>>& grid, int x, int y) {
    return x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size();
  }
};
// @lc code=end
