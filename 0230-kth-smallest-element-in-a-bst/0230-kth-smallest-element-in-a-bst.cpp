class Solution {
public:
    
    void solve(TreeNode *root, int k, int &count, int &ans){
        if(root->left) solve(root->left, k, count, ans);
        
        count++;
        
        if(count == k){
            ans = root->val;
            return;
        }
        if(root->right) solve(root->right, k, count, ans);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        int count = 0;
        solve(root, k, count, ans);
        
        return ans;
    }
};