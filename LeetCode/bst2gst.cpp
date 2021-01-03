class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        stack<TreeNode*> s;
        TreeNode* curr = root;
        while(curr || !s.empty()){
            while(curr){
                s.push(curr);
                curr = curr->right;
            }
            curr = s.top(); s.pop();
            sum+=curr->val;
            curr->val = sum;
            curr = curr->left;
        }
        return root;
    }
};
