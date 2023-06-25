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
    
    int getLeftH(TreeNode *root){
        int h = 0;
        while(root){
            root = root->left;
            h++;
        }
        
        return h;
    }
    
    int getRightH(TreeNode *root){
        int h = 0;
        while(root){
            root = root->right;
            h++;
        }
        
        return h;
    }
    
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
        int leftH = getLeftH(root);
        int rightH = getRightH(root);
        
        if(leftH == rightH){
            return pow(2, leftH) - 1;
        }
        
        return 1 + countNodes(root->left) + countNodes(root->right);
        
        
    }
};