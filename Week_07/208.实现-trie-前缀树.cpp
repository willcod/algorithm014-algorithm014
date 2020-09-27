/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */
#include "cpp_includes.h"
// @lc code=start
class Trie {
    bool _isEnd;
    Trie* _branch[26];
public:
    /** Initialize your data structure here. */
    Trie() {
        _isEnd = false;
        memset(_branch, NULL, sizeof(_branch));
    }

    ~Trie() {
        for (auto n : _branch) {
            if (n) delete n;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto n = this;
        for (auto c : word) {
            if (!n->_branch[c-'a'])
                n->_branch[c-'a'] = new Trie();
            n = n->_branch[c-'a'];
        }
        n->_isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto n = this;
        for (auto c : word) {
            n = n->_branch[c-'a'];
            if (!n) return false;
        }
        return n->_isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto n = this;
        for (auto c : prefix) {
            n = n->_branch[c-'a'];
            if (!n) return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

