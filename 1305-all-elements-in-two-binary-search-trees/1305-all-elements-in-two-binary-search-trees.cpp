class Solution {
public:

    void helper(TreeNode *root, vector<int> &ans){
        if(root == nullptr){
            return;
        }
        helper(root->left, ans);
        ans.push_back(root->val);
        helper(root->right, ans);


    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        helper(root1, ans);
        helper(root2, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};