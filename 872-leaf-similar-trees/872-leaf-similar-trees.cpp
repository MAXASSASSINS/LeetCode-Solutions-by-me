class Solution {
public:
    void helper(TreeNode *root, vector<int> &vals) {
        if (root == nullptr){
            return;
        }
        if(root->left == nullptr && root->right == nullptr){
            vals.push_back(root->val);
            return;
        }
        helper(root->left, vals);
        helper(root->right, vals);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> vals1;
        vector<int> vals2;
        helper(root1, vals1);
        helper(root2, vals2);
        if(vals1.size() != vals2.size()){
            return false;
        }
        for (int i = 0; i < vals1.size(); ++i) {
            if(vals1.at(i) != vals2.at(i)){
                return false;
            }
        }
        return true;
    }
};