class Solution {
public:
    bool solve(string s, string t, int i, int j){
        if(j == 0 && i == 0) return true;
        if(j == 0 && i > 0) return false;
        if(i == 0 && j > 0){
            for(int k = 1; k <=j; k++){
                if(t[k - 1] != '*') return false;
            }
            return true;
        }
        
        if(s[i - 1] == t[j - 1] || t[j - 1] == '?'){
            return solve(s, t, i - 1, j - 1);
        }
        else if(t[j - 1] == '*'){
            return solve(s, t, i - 1, j) | solve(s, t, i, j - 1);
        }
        else{
            return false;
        }
    }
    
    int solveMem(string &s, string &t, int i, int j, vector<vector<int>> &dp){
        if(j == 0 && i == 0) return true;
        if(j == 0 && i > 0) return false;
        if(i == 0 && j > 0){
            for(int k = 1; k <= j; k++){
                if(t[k - 1] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i - 1] == t[j - 1] || t[j - 1] == '?'){
            return dp[i][j] = solveMem(s, t, i - 1, j - 1, dp);
        }
        else if(t[j - 1] == '*'){
            return dp[i][j] = solveMem(s, t, i - 1, j, dp) | solveMem(s, t, i, j - 1, dp);
        }
        else{
            return dp[i][j] = false;
        }
    }
    
    bool solveTab(string &s, string &t, int n, int m){
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
        
        dp[0][0] = true;
        for(int j = 1; j <= m; j++){
            bool flag = true;
            for(int k = 1; k <= j; k++){
                if(t[k - 1] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i - 1] == t[j - 1] || t[j - 1] == '?'){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if(t[j - 1] == '*'){
                    dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
                }
                else{
                    dp[i][j] = false;
                }
            }
        }
        
        return dp[n][m];       
    }
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        
        // return solve(s, p, m, n);
        // vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));
        // return solveMem(s, p, m, n, dp);
        
        return solveTab(s, p, m, n);
    }
};