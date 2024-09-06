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
private:
    TreeNode *prev, *f, *m, *l;
public:
    void solve(TreeNode *root){
        if(!root) return;
        
        solve(root->left);
        
        if(prev->val > root->val){
            if(!f){
                f = prev;
                m = root;
            }
            else{
                l = root;
            }
        }
        prev = root;
        solve(root->right);
    }
    void recoverTree(TreeNode* root) {
        prev = new TreeNode(INT_MIN);
        f = m = l = NULL;
        solve(root);
        if(f && l){
            swap(f->val, l->val);
        }
        else{
            swap(f->val, m->val);
        }
    }
};