class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int steps, const int &arrLen, int index, vector<vector<int>> &dp){
        if(steps == 0 && index == 0) return 1;
        if(steps == 0) return 0;
        
        if(dp[steps][index] != -1) return dp[steps][index];
        
        // left
        int left = 0, right = 0, stay = 0;
        if(index < arrLen - 1){
            right = solve(steps - 1, arrLen, index + 1, dp) % mod;
        }
        if(index > 0){
            left = solve(steps - 1, arrLen, index - 1, dp) % mod;
        }
        stay = solve(steps - 1, arrLen, index, dp) % mod;
        
        return dp[steps][index] = ((left + right) % mod + stay) % mod;
    }
    
    
    
    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp(steps + 1, vector<int>(steps + 1, -1));
        return solve(steps, arrLen, 0, dp) % mod;
    }
};