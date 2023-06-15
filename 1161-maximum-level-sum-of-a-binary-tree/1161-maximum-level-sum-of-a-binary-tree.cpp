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
    int maxLevelSum(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        unordered_map<int, int> m;
        int maxi = root->val;
        int maxIndex = 1;
        q.push({root, 1});
        
        while(!q.empty()){
            auto node = q.front();
            m[node.second] += node.first->val;
            q.pop();
            
            if(node.first->left){   
                q.push({node.first->left, node.second + 1});
            }
            if(node.first->right){
                q.push({node.first->right, node.second + 1});
            }
                
        }
        
        for(auto it: m){
            if(maxi < it.second){
                maxi = it.second;
                maxIndex = it.first;
            }
            else if(maxi == it.second && maxIndex > it.first ){
                maxIndex = it.first;
            }
        }
        
        return maxIndex;
        
        
    }
};