class Solution {
public:
    void helper(const vector<int> &nums, vector<vector<int>> &ans, vector<int> temp, int index) {
        if(index == nums.size()){
            return;
        }
        helper(nums, ans, temp, index + 1);
        temp.push_back(nums[index]);
        helper(nums, ans, temp, index + 1);
        ans.push_back(temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        ans.push_back(temp);
        int index = 0;
        helper(nums, ans, temp, index);
        return ans;
    }
};