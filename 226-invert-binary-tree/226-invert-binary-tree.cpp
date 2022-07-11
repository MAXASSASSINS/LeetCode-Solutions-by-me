class Solution {
public:
    void helper(TreeNode *root){
        if(root == nullptr){
            return;
        }
        if(root->left == nullptr && root->right == nullptr){
            return;
        }
        helper(root->left);
        helper(root->right);
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }


    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
};