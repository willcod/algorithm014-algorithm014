class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result = digits;

        for (int i = result.size() - 1; i >= 0; i--) {
            if (result[i] == 9) {
                result[i] = 0;
            } else {
                result[i]++;
                return result;
            }
        }

        result[0] = 1;
        result.push_back(0);
        return result;
    }
};