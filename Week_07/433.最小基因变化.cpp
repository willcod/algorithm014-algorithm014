/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> dict({bank.begin(), bank.end()});
        if (!dict.count(end)) return -1;

        unordered_set<string> head, tail, *phead, *ptail;
        head.insert(start);
        tail.insert(end);

        int ladder = 1;
        const vector<char> g = {'A', 'C', 'G', 'T'};

        while (!head.empty() && !tail.empty()) {
            if (head.size() < tail.size()) {
                phead = &head;
                ptail = &tail;
            } else {
                phead = &tail;
                ptail = &head;
            }

            unordered_set<string> temp;
            for (auto it = phead->begin(); it != phead->end(); it++) {
                string gene = *it;
                for (int i = 0; i < gene.length(); i++) {
                    char t = gene[i];
                    for (int j = 0; j < g.size(); j++) {
                        gene[i] = g[j];

                        if (ptail->count(gene)) return ladder;

                        if (dict.count(gene)) {
                            temp.insert(gene);
                            dict.erase(gene);
                        }
                    }
                    gene[i] = t;
                }
            }
            ladder++;
            phead->swap(temp);
        }
        return -1;
    }
};
// @lc code=end
