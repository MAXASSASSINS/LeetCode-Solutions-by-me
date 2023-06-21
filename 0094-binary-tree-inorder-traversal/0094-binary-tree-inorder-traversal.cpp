class Solution {
public:
    vector<int> ans;    
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> st;
        
        TreeNode *node = root;
        while(true){
            if(node){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty()) break;
                node = st.top();
                ans.push_back(node->val);
                st.pop();
                node = node->right;
            }
               
        }
        
        return ans;
    }
};