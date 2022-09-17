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
    
    int solveTab(vector<int> &nums){
        vector<int> dp(nums.size() + 2, 0);
        for (int index = nums.size() - 1; index >= 0; --index) {
            int include = nums[index] + dp[index + 2];
            int exclude = 0 + dp[index + 1];
            dp[index] = max(include, exclude);
        }
        return dp[0];
    }

    int rob(vector<int>& nums) {
//        return solve(nums, 0);
//        vector<int> dp(nums.size() + 1, -1);
//        return solveMem(nums, 0, dp);
        return solveTab(nums);
    }
};