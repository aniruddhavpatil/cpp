class Solution {
public:
  void flatten(TreeNode *root) {
    TreeNode *curr = root;
    while (curr) {
      if (curr->left && curr->right) {
        TreeNode *temp = curr->left;
        while (temp->right)
          temp = temp->right;
        temp->right = curr->right;
      }
      if (curr->left)
        curr->right = curr->left;
      curr->left = nullptr;
      curr = curr->right;
    }
    return;
  }
};