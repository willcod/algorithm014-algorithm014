class Solution {
 public:
  struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
      return a.second > b.second;
    }
  };

  vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> result;
    unordered_map<int, int> hash;
    for (auto n : nums) {
      hash[n]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> freq;
    for (auto h : hash) {
      freq.push(h);
      if (freq.size() > k) {
        freq.pop();
      }
    }

    while (!freq.empty()) {
      auto f = freq.top();
      freq.pop();
      result.push_back(f.first);
    }
    return result;
  }
};