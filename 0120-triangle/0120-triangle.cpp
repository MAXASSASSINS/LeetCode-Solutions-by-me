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
    
    int solveTab(vector<vector<int>> &triangle){
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n));
        
        for(int i = 0; i < n; i++){
            dp[n - 1][i] = triangle[n - 1][i];
        }
        
        for(int i = n - 2; i >= 0; i--){
            for(int j = i; j >= 0; j--){
                int below = triangle[i][j] + dp[i + 1][j];
                int adj = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(below, adj);
            }
        }
        
        return dp[0][0];
        
    }
    
    int spaceOptimisation(vector<vector<int>> &triangle){
        int n = triangle.size();
        vector<int> prev(n);
        
        for(int i = 0; i < n; i++){
            prev[i] = triangle[n - 1][i];
        }
        
        for(int i = n - 2; i >= 0; i--){
            vector<int> curr(n);
            for(int j = i; j >= 0; j--){
                int below = triangle[i][j] + prev[j];
                int adj = triangle[i][j] + prev[j + 1];
                curr[j] = min(below, adj);
            }
            prev = curr;
        }
        
        return prev[0];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // return solve(triangle, 0, 0, n);
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        // return solveMem(triangle, 0, 0, n, dp);
        
        // return solveTab(triangle);
        
        return spaceOptimisation(triangle);
        
        
    }
};