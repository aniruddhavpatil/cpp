class Solution {
public:
    int maxD;
    int maxDepth(TreeNode* root){
        if(!root) return 0;
        return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
    }
    int sumLeaves(TreeNode* root, int d){
        if(!root) return 0;
        if(d == maxD){
            return root->val;
        }
        return sumLeaves(root->left, d+1) + sumLeaves(root->right, d+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        maxD = maxDepth(root);
        return sumLeaves(root, 1);
    }
};