/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */
#include "cpp_includes.h"
// @lc code=start
class TrieNode {
 public:
  string word = "";
  vector<TrieNode*> nodes;

  TrieNode() : nodes(26) {}
};
class Solution {
 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    if (board.empty() || board[0].empty()) return {};
    int rows = board.size();
    int cols = board[0].size();

    TrieNode* root = new TrieNode();
    for (string word : words) {
      TrieNode* cur = root;
      for (int i = 0; i < word.size(); i++) {
        int index = word[i] - 'a';
        if (cur->nodes[index] == 0) cur->nodes[index] = new TrieNode();

        cur = cur->nodes[index];
      }
      cur->word = word;
    }

    vector<string> res;

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        dfsSearch(res, board, root, i, j);
      }
    }

    return res;
  }

  void dfsSearch(vector<string>& res, vector<vector<char>>& board,
                 TrieNode* root, int x, int y) {
    if (!isValid(board, x, y)) return;
    char c = board[x][y];
    if (c == '.' || root->nodes[c - 'a'] == 0) return;
    root = root->nodes[c - 'a'];
    if (root->word != "") {
      res.push_back(root->word);
      root->word = "";
    }

    board[x][y] = '.';
    dfsSearch(res, board, root, x - 1, y);
    dfsSearch(res, board, root, x, y - 1);
    dfsSearch(res, board, root, x + 1, y);
    dfsSearch(res, board, root, x, y + 1);
    board[x][y] = c;
  }

  bool isValid(vector<vector<char>>& board, int x, int y) {
    return x >= 0 && y >= 0 && x < board.size() && y < board[0].size();
  }
};
// @lc code=end
