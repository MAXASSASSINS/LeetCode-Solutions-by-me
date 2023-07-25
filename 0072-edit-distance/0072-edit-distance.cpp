class Solution {
public:
    int solve(string s, string t, int i, int j){
        if(i < 0) return j + 1;
        if(j < 0) return i + 1;
        
        
        
        if(s[i] == t[j]){
            return solve(s, t, i - 1, j - 1); 
        }
        else{
            int insert = solve(s, t, i, j - 1);
            int remove = solve(s, t, i - 1, j);
            int replace = solve(s, t, i - 1, j - 1);
            return 1 + min(insert, min(remove, replace));
        }
    }
    
    int solveMem(string s, string t, int i, int j, vector<vector<int>> &dp){
        if(i == 0) return j;
        if(j == 0) return i;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i - 1] == t[j - 1]){
            return dp[i][j] = solveMem(s, t, i - 1, j - 1, dp); 
        }
        else{
            int insert = solveMem(s, t, i, j - 1, dp);
            int remove = solveMem(s, t, i - 1, j, dp);
            int replace = solveMem(s, t, i - 1, j - 1, dp);
            return dp[i][j] = 1 + min(insert, min(remove, replace));
        }
    }
    
    int solveTab(string s, string t, int m, int n){
        return 0;
    }
    
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        
        // return solve(word1, word2, m - 1, n - 1);
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solveMem(word1, word2, m, n, dp);
        
        // return solveTab(word1, word2, m, n);
    }
};