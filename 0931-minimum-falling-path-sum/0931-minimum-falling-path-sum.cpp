class Solution {
public:
    
    int solve(vector<vector<int>> &matrix, int row, int col, vector<vector<int>> &dp){
        if(row == matrix.size()) return 0;
        
        if(dp[row][col] != INT_MAX) return dp[row][col];
        
        int dleft = INT_MAX, dright = INT_MAX, bottom = INT_MAX;
        
        if(col > 0) dleft = matrix[row][col - 1] + solve(matrix, row + 1, col - 1, dp);
        if(col < matrix[0].size() - 1) dright = matrix[row][col + 1] + solve(matrix, row + 1, col + 1,dp);
        bottom = matrix[row][col] + solve(matrix, row + 1, col, dp);
        
        return dp[row][col] = min(bottom, min(dleft, dright));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        for(int i = 0; i < matrix[0].size(); i++){
            vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), INT_MAX));
            ans = min(ans, matrix[0][i] + solve(matrix, 1, i, dp));
        }
        return ans;
    }
};