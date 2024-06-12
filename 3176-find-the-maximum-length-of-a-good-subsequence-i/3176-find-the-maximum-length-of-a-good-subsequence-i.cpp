class Solution {
public:
    int solve(vector<int> &nums, int k ,int index, int lastIdx, vector<vector<vector<int>>> &dp){
        if(index >= nums.size()){
            return 0;
        }
        
        if(dp[k][index][lastIdx + 1] != -1) return dp[k][index][lastIdx + 1];
        
        int excl = solve(nums, k, index + 1, lastIdx, dp);
        int incl = 0;
        if(lastIdx == -1 || nums[lastIdx] == nums[index]){
            incl = 1 + solve(nums, k, index + 1, index, dp);
        }
        else if(k > 0){
            incl = 1 + solve(nums, k - 1, index + 1, index, dp);
        }
        
        return dp[k][index][lastIdx + 1] = max(incl, excl);
    }
    
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(k + 1, vector<vector<int>> (n + 1, vector<int>(n + 1, -1)));
        return solve(nums, k, 0, -1, dp);
    }
};