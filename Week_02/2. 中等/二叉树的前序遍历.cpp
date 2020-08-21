class Solution1 {
 public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    travel(root, res);
    return res;
  }

  void travel(TreeNode* root, vector<int>& res) {
    if (!root) return;

    res.push_back(root->val);
    if (root->left) travel(root->left, res);
    if (root->right) travel(root->right, res);
  }
};

class Solution2 {
 public:
  vector<int> preorderTraversal(TreeNode* root) {
    if (!root) return {};
    vector<int> result;
    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
      TreeNode* node = st.top();
      if (node != nullptr) {
        st.pop();
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
        st.push(node);
        st.push(nullptr);
      } else {
        st.pop();
        node = st.top();
        st.pop();
        result.push_back(node->val);
      }
    }
    return result;
  }
};