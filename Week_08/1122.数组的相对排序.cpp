/*
 * @lc app=leetcode.cn id=1122 lang=cpp
 *
 * [1122] 数组的相对排序
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int tmp = 0;
        for (int i = 0; i < arr2.size(); i++) {
            for (int j = 0; j < arr1.size(); j++) {
                if (arr2[i] == arr1[j]) {
                    swap(arr1[tmp++], arr1[j]);
                }
            }
        }

        sort(arr1.begin() + tmp, arr1.end());

        return arr1;
    }
};
// @lc code=end
