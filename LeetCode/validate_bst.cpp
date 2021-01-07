class Solution {
public:
  bool isValidBST(TreeNode *root) {
    if (!root)
      return true;
    TreeNode *curr = root, *prev = nullptr;
    stack<TreeNode *> s;
    while (curr || !s.empty()) {
      while (curr) {
        s.push(curr);
        curr = curr->left;
      }
      curr = s.top();
      s.pop();
      if (prev && prev->val >= curr->val) {
        return false;
      }
      prev = curr;
      curr = curr->right;
    }
    return true;
  }
};