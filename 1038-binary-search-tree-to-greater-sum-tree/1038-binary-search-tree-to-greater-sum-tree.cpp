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
    void inorder(TreeNode *root, vector<int> &vec){
        if(!root) return;
        
        if(root->left){
            inorder(root->left, vec);
        }
        vec.push_back(root->val);
        if(root->right){
            inorder(root->right, vec);
        }
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> vec;
        inorder(root, vec);
        unordered_map<int,int> m;
        int n = vec.size();
        m[vec[n - 1]] = vec[n - 1];
        for(int i = n - 2; i >= 0; i--){
            m[vec[i]] = m[vec[i + 1]] + vec[i];
        }
        
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            node->val = m[node->val];
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        
        return root;
    }
};