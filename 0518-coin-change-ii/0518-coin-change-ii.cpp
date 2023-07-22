class Solution {
public:
    int solve(vector<int> &coins, int index, int target){
        if(index == 0){
            if(target % coins[index] == 0) return 1;
            return 0;
        }
        int excl = solve(coins, index - 1, target);
        int incl = 0;
        if(coins[index] <= target){
            incl = solve(coins, index, target - coins[index]);
        }
        return excl + incl;
    }
    
    int solveMem(vector<int> &coins, int index, int target, vector<vector<int>> &dp){
        if(index == 0){
            if(target % coins[index] == 0) return 1;
            return 0;
        }
        
        if(dp[index][target] != -1) return dp[index][target];
        
        int excl = solveMem(coins, index - 1, target, dp);
        int incl = 0;
        if(coins[index] <= target){
            incl = solveMem(coins, index, target - coins[index], dp);
        }
        return dp[index][target] = excl + incl;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // return solve(coins, n - 1, amount);
        
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return solveMem(coins, n - 1, amount, dp);
    }
};