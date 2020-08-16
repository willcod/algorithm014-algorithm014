class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;

    vector<int> count(26, 0);

    for (int i = 0; i < s.length(); i++) {
      count[s[i] - 'a']++;
    }

    for (int j = 0; j < s.length(); j++) {
      count[t[j] - 'a']--;
      if (count[t[j] - 'a'] < 0) {
        return false;
      }
    }

    return true;
  }
};