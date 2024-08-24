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
    TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int l1, int r1, int l2, int r2, unordered_map<int,int> &m){
        if(l1 > r1 || l2 > r2) return nullptr;
        
        TreeNode *root = new TreeNode(preorder[l1]);
        
        int index = m[preorder[l1]];
        
        int numsLeft = index - l2;
        
        root->left = solve(preorder, inorder, l1 + 1, l1 + numsLeft, l2, index - 1, m);
        root->right = solve(preorder, inorder, l1 + numsLeft + 1, r1 ,index + 1, r2, m);    
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {  
        int n = inorder.size();
        
        unordered_map<int,int> m;
        for(int i = 0; i < n; i++){
            m[inorder[i]] = i;
        }
        
        return solve(preorder, inorder, 0, n - 1, 0, n - 1, m);
    }
};