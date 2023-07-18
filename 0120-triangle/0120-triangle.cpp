class Solution {
public:
    int solve(vector<vector<int>> &triangle, int i, int j, const int &n){
        if(i == n - 1) return triangle[i][j];
        
        int below = triangle[i][j] + solve(triangle, i + 1, j, n);
        int adj = triangle[i][j] + solve(triangle, i + 1, j + 1, n);
        
        return min(below, adj);
    }
    
    int solveMem(vector<vector<int>> &triangle, int i, int j, const int &n, vector<vector<int>> &dp){
        if(i == n - 1) return triangle[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int below = triangle[i][j] + solveMem(triangle, i + 1, j, n, dp);
        int adj = triangle[i][j] + solveMem(triangle, i + 1, j + 1, n, dp);
        
        return dp[i][j] = min(below, adj);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // return solve(triangle, 0, 0, n);
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return solveMem(triangle, 0, 0, n, dp);
        
        
    }
};