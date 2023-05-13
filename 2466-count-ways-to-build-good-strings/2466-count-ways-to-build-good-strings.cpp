int MOD = 1e9 + 7;

class Solution {
public:

    int solve(int low, int high, int zero, int one, int len){
        if(len > high){
            return 0;
        }  
        
        // appending zero
        int a0 = 0;
        int a1 = 0;
        if(len + zero <= high){
            if(len + zero >= low){
                a0 = 1 + solve(low, high, zero, one, len + zero);
            }
            else{
                a0 = solve(low, high, zero, one, len + zero);
            }
        }
        
        if(len + one <= high){
            if(len + one >= low){
                a1 = 1 + solve(low, high, zero, one, len + one);
            }
            else{
                a1 = solve(low, high, zero, one, len + one);
            }
        }
        
        
        return a0 + a1;
        
        
    }
    
    int solveMem(int low, int high, int zero, int one, int len, vector<int> &dp){
        if(len > high){
            return 0;
        }
        
        if(dp[len] != -1) return dp[len];
        
        // appending zero
        int a0 = 0;
        int a1 = 0;
        if(len + zero <= high){
            if(len + zero >= low){
                a0 = 1 + solveMem(low, high, zero, one, len + zero, dp) % MOD;
            }
            else{
                a0 = solveMem(low, high, zero, one, len + zero, dp) % MOD;
            }
        }
        
        if(len + one <= high){
            if(len + one >= low){
                a1 = 1 + solveMem(low, high, zero, one, len + one, dp) % MOD;
            }
            else{
                a1 = solveMem(low, high, zero, one, len + one, dp) % MOD;
            }
        }
        
        
        return dp[len] = (a0 + a1)%MOD;
        
    }
    
    
    
    int countGoodStrings(int low, int high, int zero, int one) {
        
        // return solve(low, high, zero, one, 0) % MOD;
        
        vector<int> dp(high + 1, -1);
        return solveMem(low, high, zero, one, 0, dp);
        
        
    }
};