class Solution {
public:
    int solve(vector<int> &prices, int buy, int index, int fee){
        if (index == prices.size()){
            return 0;
        }
        int profit = 0;
        if (buy){
            int buyKaro = -prices[index] + solve(prices, 0, index + 1, fee);
            int skipKaro = solve(prices, 1, index + 1, fee);
            profit = max(buyKaro, skipKaro);
        }
        else{
            int sellKaro = prices[index] - fee + solve(prices, 1, index + 1, fee);
            int skipKaro = solve(prices, 0, index + 1, fee);
            profit = max(sellKaro, skipKaro);
        }
        return profit;
    }

    int solveMem(vector<int> &prices, int buy, int index, vector<vector<int>> &dp, int fee){
        if (index == prices.size()){
            return 0;
        }
        if (dp[index][buy] != -1)
            return dp[index][buy];
        int profit = 0;
        if (buy){
            int buyKaro = -prices[index] + solveMem(prices, 0, index + 1, dp, fee);
            int skipKaro = solveMem(prices, 1, index + 1, dp,fee);
            profit = max(buyKaro, skipKaro);
        }
        else{
            int sellKaro = prices[index] - fee + solveMem(prices, 1, index + 1, dp, fee);
            int skipKaro = solveMem(prices, 0, index + 1,dp, fee);
            profit = max(sellKaro, skipKaro);
        }
        return dp[index][buy] = profit;
    }

    int solveTab(vector<int> &prices, int fee){
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int> (2, 1));
        for (int index = n - 1; index >= 0 ; --index) {
            for (int buy = 0; buy <= 1; ++buy) {
                int profit = 0;
                if (buy){
                    int buyKaro = -prices[index] + dp[index + 1][0];
                    int skipKaro = dp[index + 1][1];
                    profit = max(buyKaro, skipKaro);
                }
                else{
                    int sellKaro = prices[index] - fee + dp[index + 1][1];
                    int skipKaro = dp[index + 1][0];
                    profit = max(sellKaro, skipKaro);
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1] - 1;
    }

    int solveSO(vector<int> &prices, int fee){
        int n = prices.size();
        vector<int> curr(2, 0);
        vector<int> next(2, 0);
        vector<vector<int>> dp(n + 1, vector<int> (2, 1));
        for (int index = n - 1; index >= 0 ; --index) {
            for (int buy = 0; buy <= 1; ++buy) {
                int profit = 0;
                if (buy){
                    int buyKaro = -prices[index] + next[0];
                    int skipKaro = next[1];
                    profit = max(buyKaro, skipKaro);
                }
                else{
                    int sellKaro = prices[index] - fee + next[1];
                    int skipKaro = next[0];
                    profit = max(sellKaro, skipKaro);
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return next[1];
    }

    int maxProfit(vector<int>& prices, int fee) {
       // return solve(prices, 1, 0, fee);
        // int n = prices.size();
        // vector<vector<int>> dp(n + 1, vector<int> (2, -1));
//        return solveMem(prices, 1,   0, dp, fee);
        // return solveTab(prices, fee);
       return solveSO(prices, fee);
    }
};