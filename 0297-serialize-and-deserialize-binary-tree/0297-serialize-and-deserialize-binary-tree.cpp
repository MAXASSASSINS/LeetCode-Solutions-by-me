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
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            if(node){
                s += to_string(node->val); 
                q.push(node->left);
                q.push(node->right);
            }
            else{
                s += "n";
            }
            s += " ";
            
        }
        
        cout<<s<<endl;
        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return nullptr;
        vector<string> vec;
        
        string str;
        
        stringstream s(data);
        
        getline(s, str, ' ');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode *> q;
        q.push(root);
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            getline(s, str, ' ');
            if(str == "n"){
                node->left = nullptr;
            }
            else{
                TreeNode *left = new TreeNode(stoi(str));
                node->left = left;
                q.push(node->left);
            }
            
            getline(s, str, ' ');
            if(str == "n"){
                node->right = nullptr;
            }
            else{
                TreeNode *right = new TreeNode(stoi(str));
                node->right = right;
                q.push(node->right);
            }
        }
        
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));