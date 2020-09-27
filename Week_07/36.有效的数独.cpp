/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    bool rows[9][10] = {0, 0};
    bool cols[9][10] = {0, 0};
    bool blocks[9][10] = {0, 0};

    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.') continue;

        int val = board[i][j] - '0';

        if (rows[i][val]) return false;
        if (cols[j][val]) return false;
        if (blocks[j / 3 + i / 3 * 3][val]) return false;

        rows[i][val] = true;
        cols[j][val] = true;
        blocks[j / 3 + i / 3 * 3][val] = true;
      }
    }

    return true;
  }
};
// @lc code=end
