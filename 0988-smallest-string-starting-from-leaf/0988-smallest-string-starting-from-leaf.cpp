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
    
    void getAllStrings(TreeNode *root, string &ans, string s){
        if(!root->left && !root->right){
            s += 'a' + root->val;
            string t;
            for(int i = s.length() - 1; i >= 0; i--){
                t += s[i];
            }
            if(ans == "" || t < ans) ans = t;
        } 
        s += 'a' + root->val;
        if(root->left) getAllStrings(root->left, ans, s);
        if(root->right) getAllStrings(root->right, ans, s);

    }
    
    string smallestFromLeaf(TreeNode* root) {
        string ans;
        getAllStrings(root, ans, "");
        return ans;
    }
};