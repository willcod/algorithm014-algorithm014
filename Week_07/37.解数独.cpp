/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  void solveSudoku(vector<vector<char>>& board) { solveSudoku(board, 0, 0); }

  bool solveSudoku(vector<vector<char>>& board, int x, int y) {
    if (x == 9) return true;
    if (y == 9) return solveSudoku(board, x + 1, 0);
    if (board[x][y] != '.') return solveSudoku(board, x, y + 1);

    for (char c = '1'; c <= '9'; c++) {
      if (check(board, x, y, c)) {
        board[x][y] = c;
        if (solveSudoku(board, x, y + 1)) return true;
        board[x][y] = '.';
      }
    }
    return false;
  }

  bool check(vector<vector<char>>& board, int x, int y, char c) {
    int row = x - x % 3;
    int col = y - y % 3;

    for (int i = 0; i < 9; i++) {
      if (board[i][y] == c) return false;
    }

    for (int i = 0; i < 9; i++) {
      if (board[x][i] == c) return false;
    }

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (board[row + i][col + j] == c) return false;
      }
    }

    return true;
  }
};
// @lc code=end
