class Solution {
 public:
  int trap(vector<int>& height) {
    if (height.empty()) return 0;

    int leftMax = 0;
    int rightMax = 0;
    int result = 0;

    int i = 0;
    int j = height.size() - 1;
    while (i < j) {
      leftMax = max(leftMax, height[i]);
      rightMax = max(rightMax, height[j]);

      if (leftMax < rightMax) {
        result += leftMax - height[i++];
      } else {
        result += rightMax - height[j--];
      }
    }
    return result;
  }
};