class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> cache;

    for (int i = 0; i < nums.size(); i++) {
      int num2 = target - nums[i];
      if (cache.find(num2) != cache.end()) {
        return {cache[num2], i};
      }
      cache[nums[i]] = i;
    }

    return {0, 0};
  }
};