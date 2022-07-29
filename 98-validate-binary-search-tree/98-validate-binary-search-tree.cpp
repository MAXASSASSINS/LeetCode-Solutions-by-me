class Solution {
public:
    void inorder(TreeNode *root, vector<int> &temp){
        if(root == nullptr){
            return;
        }
        inorder(root->left, temp);
        temp.push_back(root->val);
        inorder(root->right, temp);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> temp;
        inorder(root, temp);
        for (int i = 1; i < temp.size(); ++i) {
            if(temp[i] <= temp[i - 1]){
                return false;
            }
        }
        return true;
    }
};