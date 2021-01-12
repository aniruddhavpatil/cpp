class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        stack<TreeNode*> so, sc;
        
        while(original || !so.empty()){
            while(original){
                so.push(original);
                sc.push(cloned);
                original = original -> left;
                cloned = cloned -> left;
            }
            original = so.top(); so.pop();
            cloned = sc.top(); sc.pop();
            if(original == target) return cloned;
            original = original->right;
            cloned = cloned->right;
        }
        return NULL;
    }
};