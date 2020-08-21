class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    unordered_map<string, int> hash;
    int sub = 0;
    for (auto str : strs) {
      string temp = str;
      sort(temp.begin(), temp.end());

      if (hash.find(temp) != hash.end()) {
        res[hash[temp]].push_back(str);
      } else {
        vector<string> newAnagram(1, str);
        res.push_back(newAnagram);
        hash[temp] = sub++;
      }
    }

    return res;
  }
};