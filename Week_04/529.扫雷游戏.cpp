/*
 * @lc app=leetcode.cn id=529 lang=cpp
 *
 * [529] 扫雷游戏
 */

// @lc code=start
class Solution {
 public:
  vector<vector<char>> updateBoard(vector<vector<char>>& board,
                                   vector<int>& click) {
    if (board[click[0]][click[1]] == 'M') {
      board[click[0]][click[1]] = 'X';
      return board;
    }

    Dfs(board, click[0], click[1]);
    return board;
  }

 private:
  void Dfs(vector<vector<char>>& board, int x, int y) {
    if (!isValid(board, x, y)) return;

    if (board[x][y] == 'E') {
      vector<vector<int>> offset = {{1, 0},  {0, 1},  {-1, 0}, {0, -1},
                                    {1, -1}, {-1, 1}, {1, 1},  {-1, -1}};
      int count = 0;

      for (int i = 0; i < 8; i++) {
        int xd = x + offset[i][0];
        int yd = y + offset[i][1];
        if (isValid(board, xd, yd) && board[xd][yd] == 'M') count++;
      }
      if (count > 0) {
        board[x][y] = count + '0';
      } else {
        board[x][y] = 'B';
        for (int i = 0; i < 8; i++) {
          int xd = x + offset[i][0];
          int yd = y + offset[i][1];
          Dfs(board, xd, yd);
        }
      }
    }
  }

  bool isValid(vector<vector<char>>& board, int x, int y) {
    return x >= 0 && x < board.size() && y >= 0 && y < board[0].size();
  }
};
// @lc code=end
