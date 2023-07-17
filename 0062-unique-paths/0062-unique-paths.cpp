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
    
    int solveTab(int m, int n){
        vector<vector<int>> dp(m, vector<int>(n));
        
        dp[0][0] = 1;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) continue;
                int left = j > 0 ? dp[i][j - 1] : 0;
                int top = i > 0 ? dp[i - 1][j] : 0;
                dp[i][j] = left + top;
            }
        }
        
        return dp[m - 1][n - 1];
        
    }
    
    int spaceOptimisation(int m, int n){
        vector<int> prev(n);
        
        prev[0] = 1;
        
        for(int i = 0; i < m; i++){
            vector<int> curr(n);
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    curr[j] = 1;
                    continue;
                }
                int left = j > 0 ? curr[j - 1] : 0;
                int top = i > 0 ? prev[j] : 0;
                curr[j] = left + top;
            }
            
            prev = curr;
        }
        
        return prev[n - 1];
    }
    
    int uniquePaths(int m, int n) {
        // return solve(m - 1,n - 1);
        
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return solveMem(m - 1, n - 1, dp);
        
        // return solveTab(m, n);
        return spaceOptimisation(m, n);
    }
};