class Solution {
public:
    vector<int> arr;
    void helper(TreeNode *root){
        if (root == nullptr)
            return;
        helper(root->left);
        arr.push_back(root->val);
        helper(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        helper(root);
        int low = 0;
        int high = arr.size() - 1;
        while (low < high){
            if(arr[high] + arr[low] > k)
                high--;
            else if(arr[high] + arr[low] < k)
                low++;
            else if(arr[high] + arr[low] == k){
                return true;
            }
        }
        return false;
    }
};