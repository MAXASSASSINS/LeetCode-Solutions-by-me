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

typedef pair<TreeNode *, TreeNode *> pi;

class Solution {
public:
    int solve(TreeNode *root, unordered_map<TreeNode *, int> &dp){
        if(!root) return 0;
        
        if(dp.find(root) != dp.end()) return dp[root];
        
        int excl = 0;
        excl += solve(root->left, dp);
        excl += solve(root->right, dp);
        
        int incl = root->val;
        if(root->left){
            incl += solve(root->left->left, dp);
            incl += solve(root->left->right, dp);
        }
        if(root->right){
            incl += solve(root->right->left, dp);
            incl += solve(root->right->right, dp);
        }

        return dp[root] = max(incl, excl);
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode *, int> dp;
        return solve(root, dp);   
    }
};