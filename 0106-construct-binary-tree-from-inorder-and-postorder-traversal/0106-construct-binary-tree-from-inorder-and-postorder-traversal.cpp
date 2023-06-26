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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        unordered_map<int,int> m;
        for(int i = 0; i < inorder.size(); i++){
            m[inorder[i]] = i;
        }
        
        TreeNode *ans = solve(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, m);
        
        return ans;
    }
    
    TreeNode *solve(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder,
                 int poStart, int poEnd, unordered_map<int,int> &m){
        
        if(inStart > inEnd || poStart > poEnd) return NULL;
        
        TreeNode *root = new TreeNode(postorder[poEnd]);
        
        int inRoot = m[root->val];
        int numsLeft = inRoot - inStart;
        
        root->left = solve(inorder, inStart, inRoot - 1, postorder, poStart , poStart + numsLeft - 1, m);
        root->right = solve(inorder, inRoot + 1, inEnd, postorder, poStart + numsLeft, poEnd - 1, m);
        
        return root;
        
    }
};