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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> m;
        queue<pair<TreeNode*, vector<int>>> q;
        q.push({root, {0, 0}});
        
        while(!q.empty()){
            auto p = q.front();
            auto node = p.first;
            int col = p.second[0];
            int level = p.second[1];
            m[col][level].insert(node->val);
            q.pop();
            
            if(node->left){
                q.push({node->left, {col - 1, level + 1}});
            }
            if(node->right){
                q.push({node->right, {col + 1, level + 1}});
            }
        }
        
        
        for(auto it = m.begin(); it != m.end(); it++){
            auto m2 = it->second;
            vector<int> temp;
            for(auto it2 = m2.begin(); it2 != m2.end(); it2++){
                auto m3 = it2->second;
                for(auto it3 = m3.begin(); it3 != m3.end(); it3++){
                    temp.push_back(*it3);
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
        
    }
};