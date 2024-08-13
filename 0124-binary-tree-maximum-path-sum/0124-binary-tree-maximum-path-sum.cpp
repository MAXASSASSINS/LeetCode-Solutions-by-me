/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode *root, int &maxi){
        if(!root) return 0;
        
        int left = solve(root->left, maxi);
        int right = solve(root->right, maxi);
        
        int total = left + right;
        
        maxi = max(maxi, max(max(max(left, right), total) + root->val, root->val));
        return max(max(left, right) + root->val, root->val);
    }
    
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        solve(root, maxi);
        return maxi;
    }
};