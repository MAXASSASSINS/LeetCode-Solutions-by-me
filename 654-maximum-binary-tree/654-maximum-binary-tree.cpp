class Solution {
public:
    int maxValIndex(const vector<int> &nums, int leftIndex, int rightIndex){
        int maxVal = INT_MIN;
        int index = -1;
        for (int i = leftIndex; i < rightIndex; ++i) {
            if(nums[i] > maxVal){
                maxVal = nums[i];
                index = i;
            }
        }
        return index;
    }


    TreeNode* helper(vector<int> &nums, int leftIndex, int rightIndex){
        int index = maxValIndex(nums, leftIndex, rightIndex);
        if(leftIndex == rightIndex){
            return nullptr;
        }
        TreeNode *root = new TreeNode(nums[index]);
        root->left = helper(nums, leftIndex, index);
        root->right = helper(nums, index + 1, rightIndex);
        return root;
    }


    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int leftIndex = 0;
        int rightIndex = nums.size();
        TreeNode *root = nullptr;
        return  helper(nums, leftIndex, rightIndex);
    }
};