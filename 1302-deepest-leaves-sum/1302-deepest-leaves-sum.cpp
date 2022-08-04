class Solution {
public:
    void helper(TreeNode *root, int &ans, int &maxDepth, int currentDepth){
        if(root == nullptr){
            return;
        }
        if(root->left == nullptr && root->right == nullptr){
            if (currentDepth > maxDepth) {
                ans = root->val;
                maxDepth = currentDepth;
            } else if (currentDepth == maxDepth) {
                ans += root->val;
            }
            return;
        }
        helper(root->left, ans, maxDepth, currentDepth + 1);
        helper(root->right, ans, maxDepth, currentDepth + 1);
    }

    int deepestLeavesSum(TreeNode* root) {
        int maxDepth = 0;
        int currentDepth = 0;
        int ans = 0;
        helper(root, ans, maxDepth, currentDepth);
        return ans;
    }
};