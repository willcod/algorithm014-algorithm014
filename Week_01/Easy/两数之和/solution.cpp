class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashTable;

        for (int i = 0; i < nums.size(); i++) {
            int left = target - nums[i];
            
            if ( hashTable.find(left) != hashTable.end()) {
                return {hashTable[left], i};
            }

            hashTable[nums[i]] = i;
        }

        return {0, 0};
    }
};