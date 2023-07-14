class Solution {
public:
    
    int ans = 0;
    int solve(int n){
        if(n <= 1) return 1;
        return solve(n - 1) + solve(n - 2);
    }
    
    int solveMem(int n, vector<int> &dp){
        if(n <= 1) return 1;
            
        if(dp[n] != -1) return dp[n];
        
        return dp[n] =  solveMem(n - 1, dp) + solveMem(n - 2, dp);
    }
    
    int climbStairs(int n) {
        // return solve(n);
        
        vector<int> dp(n + 1, -1);
        return solveMem(n, dp);

    }
};