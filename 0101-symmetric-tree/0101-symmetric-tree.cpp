class Solution {
public:
    bool helper(TreeNode *leftSubtree, TreeNode *rightSubtree) {
        if(leftSubtree == nullptr && rightSubtree == nullptr){
            return true;
        }
        if (leftSubtree == nullptr || rightSubtree == nullptr){
            return false;
        }
        if(leftSubtree->val != rightSubtree->val){
            return false;
        }
        return helper(leftSubtree->left, rightSubtree->right) && helper(leftSubtree->right, rightSubtree->left);

    }

    bool isSymmetric(TreeNode* root) {
        TreeNode *leftSubtree = root;
        TreeNode *rightSubtree = root;
        return helper(leftSubtree, rightSubtree);
    }
};