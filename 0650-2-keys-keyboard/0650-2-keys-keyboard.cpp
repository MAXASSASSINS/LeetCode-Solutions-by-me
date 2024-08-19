class Solution {
public:
    int solve(int n, int count, int copied, vector<vector<int>> &dp){
        if(count == n) return 0;
        if(count > n) return 1e9; 
        
        if(dp[count + 2][copied + 2] != -1) return dp[count + 2][copied + 2]; 
        
        int pasteNew = 2 + solve(n, count + count, count, dp);
        int pasteOld = INT_MAX;
        if(copied != -1){
            pasteOld = 1 + solve(n, count + copied, copied, dp);
        }
        
        return dp[count + 2][copied + 2] = min(pasteOld, pasteNew);
    }
    int minSteps(int n) {
        if(n == 1) return 0;
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        return solve(n, 1, -1, dp);
        // return 0;
    }
}; 