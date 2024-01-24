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
    int solve(TreeNode *root, vector<int> &freq){
        freq[root->val]++;
        
        if(!root->left && !root->right){
            bool isPal = true;
            int cntOdd = 0;
            for(auto f: freq){
                if(f % 2 == 1) cntOdd++;
            }    
            
            freq[root->val]--;
            if(cntOdd > 1) return 0;
            else return 1;
        }
        
        int left = 0, right = 0;
        
        if(root->left) left = solve(root->left, freq);
        if(root->right) right = solve(root->right, freq);
        
        freq[root->val]--;
        return left + right;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> freq(10);
        return solve(root, freq);
    }
};