class Solution {
public:
    bool helper(TreeNode *root, int temp){
        if(root == nullptr){
            return true;
        }
        if(root->val != temp){
            return false;
        }
        return helper(root->left, temp) && helper(root->right, temp);
    }
    bool isUnivalTree(TreeNode* root) {
        int temp = root->val;
        return helper(root, temp);
    }
};