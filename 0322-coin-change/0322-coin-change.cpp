class Solution {
public:
    int solve(vector<int> &coins, int amount, int index){
        if(index == 0){
            if(amount % coins[0] == 0){
                return amount / coins[0];
            }
            return 1e8;
        }   
        int excl = solve(coins, amount, index - 1);
        int incl = INT_MAX;
        if(amount >= coins[index]){
            incl = 1 + solve(coins, amount - coins[index], index);
        }   
        return min(excl, incl);
    }
    
    int solveMem(vector<int> &coins, int amount, int index, vector<vector<int>> &dp){
        if(index == 0){
            if(amount % coins[0] == 0){
                return amount / coins[0];
            }
            return 1e8;
        }   
        
        if(dp[index][amount] != -1) return dp[index][amount];
        
        int excl = solveMem(coins, amount, index - 1, dp);
        int incl = INT_MAX;
        if(amount >= coins[index]){
            incl = 1 + solveMem(coins, amount - coins[index], index, dp);
        }   
        return dp[index][amount] = min(excl, incl);
    }
    
    
    
    
    int coinChange(vector<int>& coins, int amount) {
        // sort(coins.begin(), coins.end());
        int n = coins.size();
        if(amount == 0) return 0;
        // int ans = solve(coins, amount, n - 1);
        vector<vector<int>> dp(n + 1, vector<int> (amount + 1, -1));
        int ans = solveMem(coins, amount, n - 1, dp);
        if(ans > 1e4 + 1) return -1;
        return ans;
    }
};