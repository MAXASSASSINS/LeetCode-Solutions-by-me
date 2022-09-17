class Solution {
public:
    int solve(vector<int> &nums, int index){
        if (index >= nums.size()){
            return 0;
        }
        int include = nums[index] + solve(nums, index + 2);
        int exclude = 0 + solve(nums, index + 1);
        return max(include, exclude);
    }

    int solveMem(vector<int> &nums, int index, vector<int> &dp){
        if (index >= nums.size()){
            return 0;
        }
        if (dp[index] != -1){
            return dp[index];
        }
        int include = nums[index] + solveMem(nums, index + 2, dp);
        int exclude = 0 + solveMem(nums, index + 1, dp);
        return dp[index] = max(include, exclude);
    }

    int rob(vector<int>& nums) {
//        return solve(nums, 0);
        vector<int> dp(nums.size() + 1, -1);
        return solveMem(nums, 0, dp);
    }
};