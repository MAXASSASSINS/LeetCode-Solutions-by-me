class Solution {
public:
    void helper(TreeNode *root, int temp, long int &ans){
        if(root == nullptr)
            return;

        if(root->val > temp && root->val < ans){
            ans = root->val;
        }
        helper(root->left, temp, ans);
        helper(root->right, temp, ans);
    }

    int findSecondMinimumValue(TreeNode* root) {
        int temp = root->val;
        long int ans = pow(2,32);
        helper(root->left, temp, ans);
        helper(root->right, temp, ans);
        return ans == pow(2,32) ? (int)-1 : (int)ans;
    }
};