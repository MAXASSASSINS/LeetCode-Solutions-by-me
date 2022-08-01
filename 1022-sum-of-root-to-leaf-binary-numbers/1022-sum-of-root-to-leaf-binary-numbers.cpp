class Solution {
public:
    void helper(TreeNode* root, vector<int> &ans, int val){
        if(root == nullptr){
            return;
        }
        val = val * 2 + root->val;
        if(root->left == nullptr && root->right == nullptr){
            ans.push_back(val);
            return;
        }
        helper(root->left, ans, val);
        helper(root->right, ans, val);
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<int> ans;
        helper(root, ans, 0 );
        return std::accumulate(ans.begin(), ans.end(),0) ;
    }
};