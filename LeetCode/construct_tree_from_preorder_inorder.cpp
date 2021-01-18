class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int root = 0;
    return build(preorder, inorder, 0, inorder.size() - 1, root);
  }

  TreeNode *build(vector<int> &preorder, vector<int> &inorder, int l, int r,
                  int &root) {
    if (l > r)
      return nullptr;
    int pivot = l;
    while (inorder[pivot] != preorder[root])
      pivot++;
    root++;
    TreeNode *curr = new TreeNode(inorder[pivot]);
    curr->left = build(preorder, inorder, l, pivot - 1, root);
    curr->right = build(preorder, inorder, pivot + 1, r, root);
    return curr;
  }
};