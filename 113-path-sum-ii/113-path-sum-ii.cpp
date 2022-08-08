class Solution {
public:
    void helper(TreeNode *root, int targetSum, vector<vector<int>> &ans, int currSum, vector<int> v){
        if(root == nullptr){
            return;
        }
        currSum += root->val;
        v.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr){
            if(targetSum == currSum){
                ans.push_back(v);
            }
            return;
        }
        helper(root->left, targetSum, ans, currSum, v);
        helper(root->right, targetSum, ans, currSum, v);

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(root, targetSum, ans, 0, v);
        return ans;
    }
};