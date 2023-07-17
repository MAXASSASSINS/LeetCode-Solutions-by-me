class Solution {
public:
    int solve(int m, int n){
        if(m == 0 && n == 0) return 1;
        if(m < 0 || n < 0) return 0;
        int left = solve(m, n - 1);
        int top = solve(m - 1, n);
        return left + top;
    }
    
    int solveMem(int m, int n, vector<vector<int>> &dp){
        if(m == 0 && n == 0) return 1;
        if(m < 0 || n < 0) return 0;
        if(dp[m][n] != -1) return dp[m][n];
        int left = solveMem(m, n - 1, dp);
        int top = solveMem(m - 1, n, dp);
        return dp[m][n] = left + top;
    }
    
    int uniquePaths(int m, int n) {
        // return solve(m - 1,n - 1);
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solveMem(m - 1, n - 1, dp);
    }
};