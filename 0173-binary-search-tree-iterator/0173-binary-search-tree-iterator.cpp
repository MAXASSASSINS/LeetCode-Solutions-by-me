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
class BSTIterator {
public:
    
    int i = 0;
    vector<int> vec;
    
    void solve(TreeNode *root){
        if(!root) return;
        solve(root->left);
        vec.push_back(root->val);
        solve(root->right);
    }
    
    BSTIterator(TreeNode* root) {
        solve(root);
    }
    
    int next() {
        int ans = vec[i];
        i++;
        return ans;
    }
    
    bool hasNext() {
        if(i < vec.size()) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */