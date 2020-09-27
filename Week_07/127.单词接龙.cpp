/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict {wordList.begin(), wordList.end()};
        if (!dict.count(endWord)) return 0;
        unordered_set<string> head, tail, *phead, *ptail;

        head.insert(beginWord);
        tail.insert(endWord);

        int ladder = 2;

        while(!head.empty() && !tail.empty()) {
            if (head.size() < tail.size()) {
                phead = &head;
                ptail = &tail;
            } else {
                phead = &tail;
                ptail = &head;
            }

            unordered_set<string> temp;
            for (auto it = phead->begin(); it != phead->end(); it++) {
                string word = *it;
                for (int i = 0; i < word.length(); i++) {
                    char t = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        word[i] = c;

                        if (ptail->count(word)) return ladder;

                        if (dict.count(word)) {
                            temp.insert(word);
                            dict.erase(word);
                        }
                    }
                    word[i] = t;
                }
            }
            phead->swap(temp);
            ladder++;
        }

        return 0;
    }
};
// @lc code=end

