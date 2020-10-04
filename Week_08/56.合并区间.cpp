/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int, int> sections;
        for (auto& i : intervals) {
            int s = i[0], e = i[1];
            auto it = sections.lower_bound(i[0]);
            while (it != sections.end() && it->second <= i[1]) {
                s = min(s, it->second);
                e = max(e, it->first);
                it = sections.erase(it);
            }
            sections[e] = s;
        }
        vector<vector<int>> ans;
        for (auto& p : sections) ans.push_back({p.second, p.first});
        return ans;
    }
};
// @lc code=end
class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end(),
             [](vector<int> a, vector<int> b) { return a[0] < b[0]; });
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (res.back()[1] < intervals[i][0])
                res.push_back(intervals[i]);
            else {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }
        return res;
    }
};