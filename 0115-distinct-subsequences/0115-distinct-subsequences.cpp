class Solution {
public:
    int solve(string s, string t, int i, int j){
        if(j < 0) return 1;
        if(i < 0) return 0;
        
        if(s[i] == t[j]){
            return solve(s, t, i - 1, j - 1) + solve(s, t, i - 1, j);
        }
        else{
            return solve(s, t, i - 1, j);
        }
    }
    
    int solveMem(string s, string t, int i, int j, vector<vector<int>> &dp){
        if(j == 0) return 1;
        if(i == 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i - 1] == t[j - 1]){
            return dp[i][j] = solveMem(s, t, i - 1, j - 1, dp) + solveMem(s, t, i - 1, j, dp);
        }
        else{
            return dp[i][j] = solveMem(s, t, i - 1, j, dp);
        }
    }
    
    int solveTab(string s, string t, int n, int m){
        vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));
        
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i - 1] == t[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return (int)dp[n][m];       
    }
    
    
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
    
        // return solve(s, t, n - 1, m - 1);
        
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        // return solveMem(s, t, n, m, dp);
        
        return solveTab(s, t, n, m);
        
    }
};