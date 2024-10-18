class Solution {
public:
    int solve(vector<int> &nums, int index, int curr, const int &target, vector<vector<int>> &dp){
        if(index >= nums.size()){
            if(curr == target) return 1;
            return 0;
        }
        
        if(dp[index][curr] != -1){
            return dp[index][curr];
        }
        
        int excl = solve(nums, index + 1, curr, target, dp);
        int incl = solve(nums, index + 1, curr | nums[index], target, dp);
        
        return dp[index][curr] = incl + excl;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int x = 0;
        for(auto num: nums){
            x |= num;
        }
        vector<vector<int>> dp(nums.size() + 1, vector<int>(x + 1, -1));
        return solve(nums, 0, 0, x, dp);
    }
};