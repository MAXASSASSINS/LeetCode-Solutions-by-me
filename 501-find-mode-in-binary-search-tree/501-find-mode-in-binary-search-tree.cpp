class Solution {
public:
    void helper(TreeNode *root, int &count, int &maxCount, int &val, vector<int> &ans) {
        if (root == nullptr) {
            return;
        }
        helper(root->left, count, maxCount, val, ans);
        if (root->val == val) {
            count++;
        }
        else{
            count = 1;
        }

        if (count > maxCount) {
            maxCount = count;
            ans.clear();
            ans.push_back(root->val);
        } else if (count == maxCount) {
            ans.push_back(root->val);
        }
        val = root->val;
        helper(root->right, count, maxCount, val, ans);
    }



    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        int maxCount = INT_MIN;
        int count = 0;
        int val = INT_MIN;
        helper(root, count, maxCount, val, ans);

        return ans;
    }
};