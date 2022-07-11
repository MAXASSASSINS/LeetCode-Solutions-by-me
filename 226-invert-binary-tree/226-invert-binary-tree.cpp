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
        if (!root)
            return root;
        helper(root);
        return root;
    }
};