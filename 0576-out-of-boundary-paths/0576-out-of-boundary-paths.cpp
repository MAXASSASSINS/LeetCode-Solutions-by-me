class Solution {
public:
    int mod = 1e9 + 7;
    
    int solve(int m, int n, int maxMove, int startRow, int startColumn, vector<vector<vector<int>>> &dp){
        if(startRow == m || startColumn == n || startRow < 0 || startColumn < 0) return 1;
        if(maxMove == 0){
            return 0;
        }
        
        if(dp[startRow][startColumn][maxMove] != -1) return dp[startRow][startColumn][maxMove];
        
        
        int left = solve(m, n, maxMove - 1, startRow, startColumn - 1, dp);
        int right = solve(m, n, maxMove - 1, startRow, startColumn + 1, dp);
        int top = solve(m, n, maxMove - 1, startRow - 1, startColumn, dp);
        int bottom = solve(m, n, maxMove - 1, startRow + 1, startColumn, dp);
        
        return dp[startRow][startColumn][maxMove] =  (((((left + right) % mod) + top) % mod) + bottom) % mod;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp;
        vector<vector<int>> temp(51, vector<int>(51, -1));
        
        for(int i = 0; i < 51; i++) dp.push_back(temp);
        
        return solve(m, n, maxMove, startRow, startColumn, dp);
    }
};