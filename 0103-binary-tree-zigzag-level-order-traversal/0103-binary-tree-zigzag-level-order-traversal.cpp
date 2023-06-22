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
        
        deque<TreeNode *> q;
        if(root) q.push_front(root);
        
        bool rev = false;
        
        while(!q.empty()){
            int s = q.size();
            
            vector<int> temp;
            if(!rev){
                for(int i = 0; i < s; i++){
                    TreeNode* node = q.front();
                    q.pop_front();
                    if(node->left) q.push_back(node->left);
                    if(node->right) q.push_back(node->right);

                    temp.push_back(node->val);
                }
            }
            else{
                for(int i = 0; i < s; i++){
                    TreeNode* node = q.back();
                    q.pop_back();
                    if(node->right) q.push_front(node->right);
                    if(node->left) q.push_front(node->left);
                    temp.push_back(node->val);
                }
            }
            
            ans.push_back(temp);
            rev = !rev;
            
        }
        
        return ans;
        
    }
};