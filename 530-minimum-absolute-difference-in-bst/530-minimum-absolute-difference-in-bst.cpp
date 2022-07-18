class Solution {
public:
    void helper(TreeNode *root, int &minimum, int &prev, int &curr){
        if(root == nullptr){
            return;
        }
        helper(root->left, minimum, prev, curr);
        prev = curr;
        curr = root->val;
        minimum = min(abs(curr - prev), minimum);
        helper(root->right, minimum, prev, curr);
    }

    int getMinimumDifference(TreeNode *root) {
        int minimum = INT_MAX;
        int prev = INT_MIN;
        int curr = INT_MAX;
        helper(root, minimum, prev, curr);
        return minimum;
    }
};