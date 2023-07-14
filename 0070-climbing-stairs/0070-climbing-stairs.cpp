class Solution {
public:
    
    int ans = 0;
    int solve(int n){
        if(n <= 1) return 1;
        return solve(n - 1) + solve(n - 2);
    }
    
    int solveMem(int n, vector<int> &dp){
        if(n <= 1) return 1;
            
        if(dp[n] != -1) return dp[n];
        
        return dp[n] =  solveMem(n - 1, dp) + solveMem(n - 2, dp);
    }
    
    int solveTab(int n){
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
            
        return dp[n];
    }
    
    
    int spaceOptimise(int n){
        int a = 1, b = 1;
        
        for(int i = 2; i <= n; i++){
            int temp = a + b;
            b = a;
            a = temp;
        }
            
        return a;
    }
    
    int climbStairs(int n) {
        // return solve(n);
        
        // vector<int> dp(n + 1, -1);
        // return solveMem(n, dp);
        
        // return solveTab(n);
        return spaceOptimise(n);

    }
};