class Solution {
public:
    void helper(TreeNode *root, int &totalSum, int currNum){
        if (root == nullptr){
            return;
        }
        currNum = currNum * 10 + root->val;
        if(root->left == nullptr && root->right == nullptr){
            totalSum += currNum;
            return;
        }
        helper(root->left, totalSum, currNum);
        helper(root->right, totalSum, currNum);
    }
    int sumNumbers(TreeNode* root) {
        int totalSum = 0;
        helper(root, totalSum, 0);
        return totalSum;
    }
};