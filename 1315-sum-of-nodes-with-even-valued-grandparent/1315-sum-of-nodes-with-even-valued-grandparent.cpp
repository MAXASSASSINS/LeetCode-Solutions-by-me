class Solution {
public:
    void helper(TreeNode *root, TreeNode *parent, TreeNode *grandParent, int &sum){
        if (!root){
            return;
        }
        if(grandParent != nullptr && grandParent->val % 2 == 0){
            sum += root->val;
        }
        grandParent = parent;
        parent = root;
        helper(root->left, parent, grandParent, sum);
        helper(root->right, parent, grandParent, sum);
    }
    int sumEvenGrandparent(TreeNode* root) {
        TreeNode *parent = nullptr;
        TreeNode *grandParent = nullptr;
        int sum = 0;
        helper(root, parent, grandParent, sum);
        return sum;
    }
};