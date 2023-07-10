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
    
    int ans = INT_MAX;
    
    int bfs(TreeNode *root){
        if(!root) return 0;
        queue<TreeNode *> q;
        q.push(root);
        
        int level = 1;
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0;i < size; i++){
                auto node = q.front();
                q.pop();
                
                if(!node->left && !node->right) return level;
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            level++;
        }
        
        return level;
    }
    
    int dfs(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        // If only one of child is non-null, then go into that recursion.
        if (!root->left) {
            return 1 + dfs(root->right);
        } else if (!root->right) {
            return 1 + dfs(root->left);
        }
        
        // Both children are non-null, hence call for both childs.
        return 1 + min(dfs(root->left), dfs(root->right));
    }
    
    int minDepth(TreeNode* root) {
        // return bfs(root);
        return dfs(root);
        
    }
};