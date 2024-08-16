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
    int getHeight(TreeNode *root, bool left){
        int h = 0;
        while(root){
            root = left ? root->left : root->right;
            h++;
        }
        return h;
    }
    int solve(TreeNode *root){
        if(!root) return 0;
        int lh = getHeight(root, true);
        int rh = getHeight(root, false);
        // cout<<lh<<"\t"<<rh<<endl;
        if(lh == rh){
            return pow(2, lh) - 1;
        }
        
        int ln = solve(root->left);
        int rn = solve(root->right);
        
        // cout<<"----"<<ln<<"\t"<<rn<<endl;
        
        return 1 + ln + rn;
    }
    
    int countNodes(TreeNode* root) {
        return solve(root);
    }
};