class Solution {
public:
    int solve(vector<int> &nums, int index, int prev){
        if(index == nums.size()) return 0;
        
        
        int excl = solve(nums, index + 1, prev);
        int incl = INT_MIN;
        
        if(prev == -1 || nums[prev] < nums[index]){
            incl = 1 + solve(nums, index + 1, index);
        }
        
        return max(excl, incl);
    }
    
    int solveMem(vector<int> &nums, int index, int prev, vector<vector<int>> &dp){
        if(index == nums.size()) return 0;
        
        if(dp[index][prev + 1] != -1) return dp[index][prev + 1];
        
        int excl = solveMem(nums, index + 1, prev, dp);
        int incl = INT_MIN;
        
        if(prev == -1 || nums[prev] < nums[index]){
            incl = 1 + solveMem(nums, index + 1, index, dp);
        }
        
        return dp[index][prev + 1] = max(excl, incl);
    }
    int lengthOfLIS(vector<int>& nums) {
        // return solve(nums, 0, -1);
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n + 1, -1));
        return solveMem(nums, 0, -1, dp);
        
    }
};