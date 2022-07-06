class Solution {
public:
    void helper(int count, int &maxCount, TreeNode *root){
        if(root == nullptr){
            maxCount = max(count, maxCount);
            cout<<maxCount<<endl;
            return;
        }
        count++;
        helper(count, maxCount, root->left);
        helper(count, maxCount, root->right);

    }

    int maxDepth(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        int count = 0;
        int maxCount = 1;
        helper(count, maxCount, root);
        return maxCount;
    }
};