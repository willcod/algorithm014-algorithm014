class Solution {
 public:
  vector<int> preorder(Node* root) {
    vector<int> result;
    travel(root, result);
    return result;
  }

  void travel(Node* root, vector<int>& result) {
    if (!root) return;

    result.push_back(root->val);

    for (auto c : root->children) {
      travel(c, result);
    }
  }
};