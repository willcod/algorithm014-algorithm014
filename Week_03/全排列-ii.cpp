/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> results;
        getPermuteUnique(results, nums, 0, nums.size() -1);
        return results;
    }

    void getPermuteUnique(vector<vector<int>>& results, vector<int>& nums, int start, int end) {
        if (start == end) {
            results.push_back(nums);
            return;
        }

        unordered_set<int> set;
        for (int i = start; i <= end; i++) {
            if (set.count(nums[i]) == 1) continue;
            set.insert(nums[i]);
            swap(nums[i], nums[start]);
            getPermuteUnique(results, nums, start+1, end);
            swap(nums[i], nums[start]);
        }
    }
};
// @lc code=end

