class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr)
            return nullptr;
        TreeNode *ans;
        if(root->val == val)
            ans = root;
        else if(val > root->val){
            ans = searchBST(root->right, val);
        }
        else{
            ans = searchBST(root->left, val);
        }
        return ans;
    }
};