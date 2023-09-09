class Solution {
public:
    int solve(vector<int> &nums, int target){
        if(target == 0)
            return 1;
        if(target < 0)
            return 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans += solve(nums, target - nums[i]);
        }
        return ans;
    }
    
    int solveMem(vector<int> &nums, int target, vector<int> &dp){
        if(target < 0)
            return 0;
        if(target == 0)
            return 1;
        if(dp[target] != -1)
            return dp[target];
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans += solveMem(nums, target - nums[i], dp);
        }
        dp[target] = ans;
        
        return dp[target];       
    }
    
    int solveTab(vector<int> &nums, int target){
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        
        for(int i = 1; i <= target; i++){
            for(int j = 0; j < nums.size(); j++ ){
                if(i - nums[j] >= 0){
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return (int)dp[target];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        // return solve(nums, target);
        vector<int> dp(target + 1, -1);
        // return solveMem(nums, target, dp);
        return solveTab(nums, target);
    }
};