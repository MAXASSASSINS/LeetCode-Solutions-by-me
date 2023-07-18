class Solution {
public:
    int solve(vector<vector<int>> &grid, int m, int n){
        if(m == 0 && n == 0) return grid[0][0];
        if(m < 0 || n < 0) return 1e9;
        
        int left = grid[m][n] + solve(grid, m, n - 1);
        int top = grid[m][n] + solve(grid, m - 1, n);
        return min(top, left);
    }
    
    int solveMem(vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp){
        if(m == 0 && n == 0) return grid[0][0];
        if(m < 0 || n < 0) return 1e9;
        
        if(dp[m][n] != -1) return dp[m][n];
        
        int left = grid[m][n] + solveMem(grid, m, n - 1, dp);
        int top = grid[m][n] + solveMem(grid, m - 1, n, dp);
        return dp[m][n] = min(top, left);
    }
    
    int solveTab(vector<vector<int>> &grid){
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = grid[0][0];
                }
                else{
                    int left = INT_MAX;
                    int top = INT_MAX;
                    if(j > 0)
                        left = grid[i][j] +  dp[i][j - 1];
                    if(i > 0)
                        top = grid[i][j] + dp[i - 1][j];
                    dp[i][j] = min(top, left);
                }
            }
        }
        
        return dp[m - 1][n - 1];
        
    }
    
    int spaceOptimisation(vector<vector<int>> &grid){
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> prev(n);
        
        for(int i = 0; i < m; i++){
            vector<int> curr(n);
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    curr[j] = grid[0][0];
                }
                else{
                    int left = INT_MAX;
                    int top = INT_MAX;
                    if(j > 0)
                        left = grid[i][j] +  curr[j - 1];
                    if(i > 0)
                        top = grid[i][j] + prev[j];
                    curr[j] = min(top, left);
                }
            }
             prev = curr;
        }
        
        return prev[n - 1];
        
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // return solve(grid, m - 1, n - 1);   
        
        // vector<vector<int>> dp(m, vector<int>(n, - 1));
        // return solveMem(grid, m - 1, n - 1, dp);
        
        // return solveTab(grid);
        return spaceOptimisation(grid);
    }
};