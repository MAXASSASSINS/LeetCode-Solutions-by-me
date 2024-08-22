/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s;
        queue<TreeNode *> q;
        q.push(root);
        s += to_string(root->val);
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            if(node->left){
                q.push(node->left);  
                s += "_" + to_string(node->left->val);
            } 
            else{
                s += "_null";
            }
            if(node->right){
                q.push(node->right);
                s += "_" + to_string(node->right->val);            
            } 
            
            else{
                s += "_null";  
            }
        }
        cout<<s;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0) return nullptr;
        stringstream s(data);
        string str;
        
        getline(s, str, '_');
        
        queue<TreeNode*> q;
        TreeNode *root = new TreeNode(stoi(str));
        q.push(root);
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            getline(s, str, '_');
            if(str == "null"){
                node->left = nullptr;
            }
            else{
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }
            
            getline(s, str, '_');
            if(str == "null"){
                node->right = nullptr;
            }
            else{
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));