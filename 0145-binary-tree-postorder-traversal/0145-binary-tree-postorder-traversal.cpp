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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);
        
        unordered_set<TreeNode*> vis;
        
        while(!st.empty()){
            TreeNode *top = st.top();
            if(top->left && vis.find(top->left) == vis.end()){
                st.push(top->left);
            }
            else if(top->right && vis.find(top->right) == vis.end()){
                st.push(top->right);
            }
            else{
                vis.insert(top);
                ans.push_back(top->val);
                st.pop();
            }
        }        
        
        return ans;
    }
};