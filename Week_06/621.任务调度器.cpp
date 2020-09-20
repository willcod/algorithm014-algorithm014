/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> map;
    int count = 0;
    // maximum required cpu for most frequently appearing task
    for (auto t : tasks) {
      map[t]++;
      count = max(count, map[t]);
    }
    // after placing most frequent task at first place, there still are 
    // max_cpu - 1 instances, which must be spaced at n+1 distance this requires
    // (max_cpu - 1) * (n + 1) spaces (this did not count space for one instance
    // of most frequent task)
    int ans = (count - 1) * (n + 1);
    for (auto t : map) {
      // put most occurring task at first place, for each most frequent task,one
      // more space will be add (at the end)
      if (t.second == count) ans++;
    }
    // if number of slots in tasks array are already large enough to accomodate
    // this arrangement
    return max(static_cast<int>(tasks.size()), ans);
  }
};
// @lc code=end
