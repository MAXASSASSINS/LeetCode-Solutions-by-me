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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 1});
        int maxWidth = 0;
        
        while(!q.empty()){
            int size = q.size();
            int left = 0;
            int right = 0;
            for(int i = 0; i < size; i++){                
                auto p = q.front();
                q.pop();
                auto node = p.first;
                auto nodeNum = p.second;
                if(i == 0) left = nodeNum;
                if(i == size - 1) right = nodeNum;
                cout<<left<<"\t"<<right<<endl;
                if(node->left) q.push({node->left, nodeNum * 2LL - left});
                if(node->right) q.push({node->right, nodeNum * 2LL + 1 - left});
            }
            maxWidth = max(maxWidth, right - left + 1);
        }
        
        return maxWidth;
    }
};