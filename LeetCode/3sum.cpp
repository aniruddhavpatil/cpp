class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int front, target, back;
    vector<vector<int>> ans;
    for (int i = 0; i < nums.size(); i++) {
      target = -nums[i];
      front = i + 1;
      back = nums.size() - 1;
      while (front < back) {
        int sum = nums[front] + nums[back];
        if (sum < target) {
          front++;
        } else if (sum > target) {
          back--;
        } else {
          ans.push_back({nums[i], nums[front], nums[back]});
          while (front < back && nums[front] == ans.back()[1])
            front++;
          while (front < back && nums[back] == ans.back()[2])
            back--;
        }
      }
      while (i + 1 < nums.size() && nums[i] == nums[i + 1])
        i++;
    }
    return ans;
  }
};