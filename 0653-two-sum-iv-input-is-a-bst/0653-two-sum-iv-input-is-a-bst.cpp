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
    bool solve(TreeNode *p, TreeNode *q, int k){
        if(p == nullptr || q == nullptr) return false;
        
        int curr = p->val + q->val;
        if(curr == k && p != q){
            return true;
        }
        else if(curr < k){
            return solve(p->right, q, k) || solve(p, q->right, k);
        }
        return solve(p->left, q, k) || solve(p, q->left, k);   
    }
    
    bool findTarget(TreeNode* root, int k) {
        return solve(root->left, root, k) || solve(root, root->right, k);
    }
};