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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        queue<TreeNode *> q;
        if(root) q.push(root);
        
        bool rev = false;
        
        while(!q.empty()){
            int s = q.size();
            
            vector<int> temp;
            for(int i = 0; i < s; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                
                temp.push_back(node->val);
            }
            
            if(rev){
                reverse(temp.begin(), temp.end());
            }
            ans.push_back(temp);
            rev = !rev;
            
        }
        
        return ans;
        
    }
};