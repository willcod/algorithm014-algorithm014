/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    for (int i = 0; i < inorder.size(); i++) {
      inorder_hash[inorder[i]] = i;
    }
    int ps = 0;
    return createTree(preorder, inorder, ps, 0, inorder.size() - 1);
  }

  TreeNode* createTree(vector<int>& preorder, vector<int>& inorder, int& ps,
                       int is, int ie) {
    if (ps >= preorder.size() || is > ie) return NULL;

    auto root = new TreeNode(preorder[ps]);
    int pos = inorder_hash[preorder[ps]];
    ps++;
    root->left = createTree(preorder, inorder, ps, is, pos - 1);
    root->right = createTree(preorder, inorder, ps, pos + 1, ie);

    return root;
  }

 private:
  unordered_map<int, int> inorder_hash;
};
// @lc code=end
