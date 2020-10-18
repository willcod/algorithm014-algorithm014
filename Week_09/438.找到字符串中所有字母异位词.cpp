/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pv(26, 0), sv(26, 0), res;
        if (s.size() < p.size()) return {};

        for (int i = 0; i < p.length(); i++) {
            pv[p[i]-'a']++;
            sv[s[i]-'a']++;
        }

        if (pv == sv) res.push_back(0);

        for (int i = p.size(); i < s.size(); i++) {
            sv[s[i] - 'a']++;
            sv[s[i-p.size()] - 'a']--;

            if(pv == sv) 
                res.push_back(i-p.size()+1);
        }
        return res;
    }
};
// @lc code=end
// TLE
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.empty()) return {};
        if (s.size() < p.size()) return {};

        int n = p.length();

        sort(p.begin(), p.end());

        vector<int> res;
        for (int i = 0; i <= s.length() - n; i++) {
            auto t = s.substr(i, n);
            sort(t.begin(), t.end());
            if (t == p) {
                res.push_back(i);
            } 
        }

        return res;
    }
};