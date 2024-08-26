/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<Node*> st;
        st.push(root);
        
        while(!st.empty()){
            auto node = st.top();
            ans.push_back(node->val);
            st.pop();
            
            for(int i = 0; i < node->children.size(); i++){
                st.push(node->children[i]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};