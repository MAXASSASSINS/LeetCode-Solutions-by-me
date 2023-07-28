class Solution {
public:
    int solve(vector<int> &nums, int i, int j){
        if(i > j) return 0;
        
        int left = nums[i] + min(solve(nums, i + 2, j), solve(nums, i + 1, j - 1));
        int right = nums[j] + min(solve(nums, i, j - 2), solve(nums, i + 1, j - 1));
        
        return max(left, right);
    }
    
    int solveMem(vector<int> &nums, int i, int j, vector<vector<int>> &dp){
        if(i > j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int left = nums[i] + min(solveMem(nums, i + 2, j, dp), solveMem(nums, i + 1, j - 1, dp));
        int right = nums[j] + min(solveMem(nums, i, j - 2, dp), solveMem(nums, i + 1, j - 1, dp));
        
        return dp[i][j] = max(left, right);
    }
    

    
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        // int p1 = solve(nums, 0, n - 1);
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int p1 = solveMem(nums, 0, n - 1, dp);
        
        int total = 0;
        for(auto x: nums) total += x;
        
        int p2 = total - p1;
        
        return p1 >= p2;
        
    }
};