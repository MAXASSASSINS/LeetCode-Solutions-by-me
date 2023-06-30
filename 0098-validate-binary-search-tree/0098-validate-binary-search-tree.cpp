class Solution {
public:
    bool inorder(TreeNode *root, long low, long high){
        if(!root) return true;
        
        if(root->val <= low || root->val >= high){
            return false;
        }
        
        bool left = inorder(root->left, low, root->val);
        bool right = inorder(root->right, root->val, high);
        
        return left && right;
        
    }

    bool isValidBST(TreeNode *root) {
        return inorder(root, LONG_MIN, LONG_MAX);
    }
};