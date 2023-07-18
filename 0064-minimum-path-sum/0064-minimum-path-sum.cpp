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
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // return solve(grid, m - 1, n - 1);   
        
        vector<vector<int>> dp(m, vector<int>(n, - 1));
        return solveMem(grid, m - 1, n - 1, dp);
    }
};