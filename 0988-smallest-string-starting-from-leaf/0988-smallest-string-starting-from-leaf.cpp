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
    
    void getAllStrings(TreeNode *root, vector<vector<int>> &ans, vector<int> s){
        if(!root->left && !root->right){
            s.push_back(root->val);
            reverse(s.begin(), s.end());
            ans.push_back(s);
            return;
        } 
        s.push_back(root->val);
        if(root->left) getAllStrings(root->left, ans, s);
        if(root->right) getAllStrings(root->right, ans, s);

    }
    
    string smallestFromLeaf(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> temp;
        getAllStrings(root, res,temp);
        
        for(auto vec: res){
            string s;
            for(auto x: vec){
                s += 'a' + x;
            }
            cout<<s<<"\t";
        }
        
        sort(res.begin(), res.end());
        
        string ans;
        for(auto x: res[0]){
                ans += 'a' + x;
        }
        
        return ans;
    }
};