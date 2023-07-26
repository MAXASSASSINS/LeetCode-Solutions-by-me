class Solution {
public:
    int solve(vector<int> &prices, int day, bool buy){
        if(day >= prices.size()){
            return 0;
        }
        
        int profit = 0;
        if(buy){
            profit = max(-prices[day] + solve(prices, day + 1, false), solve(prices, day + 1, true));     
        }
        else{
            profit = max(prices[day] + solve(prices, day + 2, true), solve(prices, day + 1, false));
        }
        return profit;
    }
    
    int solveMem(vector<int> &prices, int day, bool buy, vector<vector<int>> &dp){
        if(day >= prices.size()){
            return 0;
        }
        
        if(dp[day][buy] != -1) return dp[day][buy];
        int profit = 0;
        if(buy){
            profit = max(-prices[day] + solveMem(prices, day + 1, false, dp), solveMem(prices, day + 1, true, dp));     
        }
        else{
            profit = max(prices[day] + solveMem(prices, day + 2, true, dp), solveMem(prices, day + 1, false, dp));
        }
        return dp[day][buy] =  profit;
    }
    int maxProfit(vector<int>& prices) {
        // return solve(prices, 0, true);
        
        int n = prices.size();
        
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solveMem(prices, 0, true, dp);
    }
};