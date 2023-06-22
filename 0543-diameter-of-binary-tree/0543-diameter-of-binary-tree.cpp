class Solution {
	public:
    int ans=0;

    int height(TreeNode* root)
    {
        if(!root) return 0;

        int lHeight = height(root->left);
        int rHeight = height(root->right);

        ans= max(ans, lHeight + rHeight);
        return 1+ max( lHeight , rHeight);

    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        height(root);
        return ans;
    }
};