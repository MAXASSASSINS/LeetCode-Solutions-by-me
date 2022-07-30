class Solution {
public:
    map<int,int> inorderIndexMap;
    int preOrderIndex = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root = nullptr;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndexMap.insert(pair<int, int>(inorder[i], i));
        }
        return helper(preorder, 0, preorder.size() - 1);
    }

    TreeNode *helper(vector<int> &preorder, int left, int right){
        if(left > right){
            return nullptr;
        }
        int rootVal = preorder[preOrderIndex++];
        TreeNode *root = new TreeNode(rootVal);
        root->left = helper(preorder, left, inorderIndexMap[rootVal] - 1);
        root->right = helper(preorder, inorderIndexMap[rootVal] + 1, right);
        return root;
    }
};