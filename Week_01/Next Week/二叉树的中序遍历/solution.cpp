/*
68 / 68 个通过测试用例
状态：通过
执行用时：0 ms
内存消耗：7 MB
*/

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