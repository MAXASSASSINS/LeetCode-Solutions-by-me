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
        if(!root) return ans;
        
        queue<TreeNode *> q;
        q.push(root);
        vector<TreeNode *> vec;
        int level = 1;
        
        ans.push_back({root->val});
        
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            
            if(node->left != nullptr){
                vec.push_back(node->left);
            }
            if(node->right != nullptr){
                vec.push_back(node->right);
            }
            
            if(!q.empty()) continue;
            
            if(vec.empty()) break;
            
            // if(level % 2 == 1){
            //     reverse(vec.begin(), vec.end());
            // }
            
            vector<int> temp;
            for(auto x: vec){
                temp.push_back(x->val);
                q.push(x);
            }
            
            if(level % 2 == 1){
                reverse(temp.begin(), temp.end());
            }
            
            ans.push_back(temp);
            level++;
            vec.clear();        
        }
        return ans;
    }
};