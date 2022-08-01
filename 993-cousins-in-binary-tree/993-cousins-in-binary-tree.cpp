class Solution {
public:

    void depth(TreeNode *root, int n, int currDepth, TreeNode **parent, int &dep) {
        if (root == nullptr){
            return;
        }
        if(root->left && root->left->val == n){
            *parent = root;
        }
        if(root->right && root->right->val == n){
            *parent = root;
        }
        if (root->val == n) {
            dep = currDepth;
            return;
        }

        depth(root->left, n, currDepth + 1, parent, dep);
        depth(root->right, n, currDepth + 1, parent, dep);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode *parentX = root;
        TreeNode *parentY = root;
        int depthX = 0;
        int depthY = 0;
        depth(root, x, 0, &parentX, depthX);
        depth(root, y, 0, &parentY, depthY);
        return depthX == depthY && parentX != parentY;
    }
};