class Solution {
 public:
  vector<vector<int>> levelOrder(Node* root) {
    if (!root) return {};

    vector<vector<int>> res;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
      int n = q.size();
      vector<int> level;

      for (int i = 0; i < n; i++) {
        auto node = q.front();
        q.pop();
        level.push_back(node->val);

        for (auto e : node->children) {
          q.push(e);
        }
      }

      res.push_back(level);
    }

    return res;
  }
};