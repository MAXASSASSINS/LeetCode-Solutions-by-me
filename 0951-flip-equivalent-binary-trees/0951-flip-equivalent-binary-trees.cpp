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
    void buildMap(TreeNode *root, unordered_map<int, unordered_set<int>> &m){
        if(!root) return;
        m[-1].insert(root->val);
        stack<TreeNode *> st;
        st.push(root);
        while(!st.empty()){
            auto node = st.top();
            st.pop();
            
            if(node->left){
                m[node->val].insert(node->left->val);
                st.push(node->left);
            }
            if(node->right){
                m[node->val].insert(node->right->val);
                st.push(node->right);
            }
        }
    }
    
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        unordered_map<int, unordered_set<int>> m1, m2;
        buildMap(root1, m1);
        buildMap(root2, m2);
        return m1 == m2;
        
    }
};