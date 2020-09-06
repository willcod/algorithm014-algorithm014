/*
 * @lc app=leetcode.cn id=874 lang=cpp
 *
 * [874] 模拟行走机器人
 */

// @lc code=start
class Solution {
 public:
  int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    int ans = 0;
    set<vector<int>> ob;
    for (auto p : obstacles) ob.insert(p);

    vector<vector<int>> dd = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> pos = {0, 0};
    int dir = 0;

    for (auto c : commands) {
      if (c == -2) dir = (dir + 3) % 4;
      if (c == -1) dir = (dir + 1) % 4;

      for (int i = 0; i < c; i++) {
        vector<int> next = {pos[0] + dd[dir][0], pos[1] + dd[dir][1]};
        if (ob.count(next)) break;
        pos = next;
        ans = max(ans, pos[0] * pos[0] + pos[1] * pos[1]);
      }
    }
    return ans;
  }
};
// @lc code=end
