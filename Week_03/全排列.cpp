/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        getPermute(results, nums, 0, nums.size()-1);
        return results;
    }

    void getPermute(vector<vector<int>>& results, vector<int>& nums, int start, int end) {
        if (start == end) {
            results.push_back(nums);
        }

        for (int i = start; i <= end; i++) {
            swap(nums[i], nums[start]);
            getPermute(results, nums, start+1, end);
            swap(nums[i], nums[start]);
        }
    }
};
// @lc code=end

