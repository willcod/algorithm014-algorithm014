/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
 public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> nQueens(n, string(n, '.'));
    backtracking(res, nQueens, n, 0);
    return res;
  }

  void backtracking(vector<vector<string>>& res, vector<string>& nQueens, int n,
                    int row) {
    if (row == n) {
      res.push_back(nQueens);
      return;
    }

    for (int col = 0; col < n; col++) {
      if (isValid(nQueens, n, row, col)) {
        nQueens[row][col] = 'Q';
        backtracking(res, nQueens, n, row + 1);
        nQueens[row][col] = '.';
      }
    }
  }

  bool isValid(vector<string>& nQueens, int n, int row, int col) {
    for (int i = 0; i < row; i++) {
      if (nQueens[i][col] == 'Q') return false;
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
      if (nQueens[i][j] == 'Q') return false;
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
      if (nQueens[i][j] == 'Q') return false;
    }

    return true;
  }
};
// @lc code=end
