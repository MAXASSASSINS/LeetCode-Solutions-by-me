/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void getParentsList(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &m){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            if(node->left){
                m[node->left] = node;
                q.push(node->left);
            }
            
            if(node->right){
                m[node->right] = node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> m;
        getParentsList(root, m);
        
        unordered_set<TreeNode *> st;
        queue<TreeNode*> q;
        q.push(target);
        st.insert(target);
        
        while(!q.empty() && k > 0){
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                auto node = q.front();
                q.pop();

                if(m[node] && st.find(m[node]) == st.end()){
                    q.push(m[node]);
                    st.insert(m[node]);
                }
                if(node->left && st.find(node->left) == st.end()){
                    q.push(node->left);
                    st.insert(node->left);
                }
                if(node->right && st.find(node->right) == st.end()){
                    q.push(node->right);
                    st.insert(node->right);
                }
            }
            
            k--;
        }
        
        vector<int> ans;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            ans.push_back(node->val);
        }

        return ans;
    }
};