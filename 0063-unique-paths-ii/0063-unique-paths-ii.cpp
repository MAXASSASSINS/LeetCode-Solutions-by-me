class Solution {
public:
    bool isValid(int m, int n, vector<vector<int>>& obstacleGrid){
        if(m < 0 || n < 0) return false;
        if(obstacleGrid[m][n] == 1) return false;
        return true;    
    }
    
    int solve(int m, int n, vector<vector<int>>& obstacleGrid){
        if(m == 0 && n == 0) return 1;
        int left = isValid(m, n - 1, obstacleGrid) ? solve(m, n - 1, obstacleGrid) : 0;
        int top = isValid(m - 1, n, obstacleGrid) ? solve(m - 1, n, obstacleGrid) : 0;
        return left + top;
    }
    
    int solveMem(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp){
        if(m == 0 && n == 0) return 1;
        if(dp[m][n] != -1) return dp[m][n];
        int left = isValid(m, n - 1, obstacleGrid) ? solveMem(m, n - 1,obstacleGrid, dp) : 0;
        int top = isValid(m - 1, n, obstacleGrid) ? solveMem(m - 1, n,obstacleGrid, dp) : 0;
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
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if(obstacleGrid[0][0] == 1) return 0;
        if(obstacleGrid[m - 1][n - 1] == 1) return 0;
        
        // return solve(m - 1, n - 1, obstacleGrid);
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solveMem(m - 1, n - 1, obstacleGrid, dp);
    }   
};