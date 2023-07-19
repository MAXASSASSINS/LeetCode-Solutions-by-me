class Solution {
public:
    int solve(vector<vector<int>>& mat, int row, int col){
        if(col >= mat.size() || col < 0) 
            return 1e6;
        
        if(row == 0){
            return mat[row][col];
        }
        
        int lDiag = mat[row][col] + solve(mat, row - 1, col - 1);
        int top = mat[row][col] + solve(mat, row - 1, col);
        int rDiag = mat[row][col] + solve(mat, row - 1, col + 1);
        
        return min(lDiag, min(top, rDiag));
    }
    
    int solveMem(vector<vector<int>>& mat, int row, int col, vector<vector<int>> &dp){
        if(col >= mat.size() || col < 0) 
            return 1e6;
        
        if(row == 0){
            return mat[row][col];
        }
        
        if(dp[row][col] != -1) return dp[row][col];
        
        int lDiag = mat[row][col] + solveMem(mat, row - 1, col - 1, dp);
        int top = mat[row][col] + solveMem(mat, row - 1, col, dp);
        int rDiag = mat[row][col] + solveMem(mat, row - 1, col + 1, dp);
        
        return dp[row][col] = min(lDiag, min(top, rDiag));
    }
    
    int solveTab(vector<vector<int>> &mat){
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(n));
        
        for(int col = 0; col < n; col++){
            dp[0][col] = mat[0][col];
        }
        
        for(int row = 1; row < n; row++){
            for(int col = 0; col < n; col++){
                int lDiag = mat[row][col];
                int rDiag = mat[row][col];
                int top = mat[row][col] + dp[row - 1][col];
                
                if(col > 0) lDiag += dp[row - 1][col - 1];
                else lDiag += 1e6;
                
                
                if(col + 1 < n) rDiag += dp[row - 1][col + 1];
                else rDiag += 1e6;
                
                dp[row][col] = min(lDiag, min(top, rDiag));
            }
        }
        
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            ans = min(ans, dp[n - 1][i]);
        }
        return ans;
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        // for(int i = n; i >= 0; i--){
        //      ans = min(ans, solve(matrix, n - 1, n - 1 - i));
        // }
        
        
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // for(int i = n; i >= 0; i--){
        //     ans = min(ans, solveMem(matrix, n - 1, n - 1 - i, dp));
        // }
        
        // return ans;
        
        return solveTab(matrix);
    }
};