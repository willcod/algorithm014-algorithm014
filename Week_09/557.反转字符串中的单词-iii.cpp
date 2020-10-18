/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  string reverseWords(string s) {
    for (int i = 0, j = 0; i < s.length(); i++) {
      if (s[i] != ' ') {
        j = i + 1;
        while (s[j] != ' ' && j < s.length()) j++;
        reverse(s.begin() + i, s.begin() + j);
        i = j - 1;
      }
    }

    return s;
  }
};
// @lc code=end
class Solution {
 public:
  int getKthMagicNumber(int k) {
    set<long> q;  //可以看做小顶堆
    long ans;
    q.insert(1);
    while (k--) {
      ans = *q.begin();
      q.erase(q.begin());
      q.insert(ans * 3);
      q.insert(ans * 5);
      q.insert(ans * 7);
    }
    return ans;
  }
};