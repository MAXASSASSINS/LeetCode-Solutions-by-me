class Solution {
public:
    void helper(TreeNode *root, vector<int> &ans, int &maxDepth, int currentDepth){
        if(root == nullptr){
            return;
        }
        if(root->left == nullptr && root->right == nullptr){
            if(currentDepth > maxDepth){
                ans.clear();
                ans.push_back(root->val);
                maxDepth = currentDepth;
            }
            else if(currentDepth == maxDepth){
                ans.push_back(root->val);
            }
            return;
        }
        helper(root->left, ans, maxDepth, currentDepth + 1);
        helper(root->right, ans, maxDepth, currentDepth + 1);
    }

    int deepestLeavesSum(TreeNode* root) {
        vector<int> ans;
        int maxDepth = 0;
        int currentDepth = 0;
        helper(root, ans, maxDepth, currentDepth);
        return std::accumulate(ans.begin(), ans.end(),0);
    }
};