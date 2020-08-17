class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    inorderSub(root, result);
    return result;
  }

  void inorderSub(TreeNode* root, vector<int>& result) {
    if (!root) return;

    inorderSub(root->left, result);
    result.push_back(root->val);
    inorderSub(root->right, result);
  }
};