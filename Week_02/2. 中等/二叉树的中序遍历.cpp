class Solution1 {
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

class Solution2 {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    if (!root) return {};
    vector<int> res;
    stack<TreeNode*> stk;
    stk.push(root);

    while (!stk.empty()) {
      auto node = stk.top();
      if (node) {
        stk.pop();

        if (node->right) stk.push(node->right);
        stk.push(node);
        stk.push(NULL);
        if (node->left) stk.push(node->left);
      } else {
        stk.pop();
        auto node = stk.top();
        stk.pop();

        res.push_back(node->val);
      }
    }

    return res;
  }
};