class Solution {
public:
    int solve(vector<int> &prices, int buy, int index, int limit){
        if (index == prices.size() || limit == 0){
            return 0;
        }
        int profit = 0;
        if (buy){
            int buyKaro = -prices[index] + solve(prices, 0, index + 1, limit);
            int skipKaro = solve(prices, 1, index + 1, limit);
            profit = max(buyKaro, skipKaro);
        }
        else{
            int sellKaro = prices[index] + solve(prices, 1, index + 1, limit - 1);
            int skipKaro = solve(prices, 0, index + 1, limit);
            profit = max(sellKaro, skipKaro);
        }
        return profit;
    }

    int solveMem(vector<int> &prices, int buy, int index, vector<vector<vector<int>>> &dp, int limit){
        if (index == prices.size()){
            return 0;
        }
        if (dp[index][buy][limit] != -1)
            return dp[index][buy][limit];

        int profit = 0;
        if (buy){
            int buyKaro = -prices[index] + solveMem(prices, 0, index + 1, dp, limit);
            int skipKaro = solveMem(prices, 1, index + 1, dp, limit);
            profit = max(buyKaro, skipKaro);
        }
        else{
            int sellKaro = prices[index] + solveMem(prices, 1, index + 1, dp, limit - 1);
            int skipKaro = solveMem(prices, 0, index + 1, dp, limit);
            profit = max(sellKaro, skipKaro);
        }
        return dp[index][buy][limit] = profit;
    }

    int solveTab(int k, vector<int> &prices){
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (k + 1, 0)));
        for (int index = n - 1; index >= 0 ; --index) {
            for (int buy = 0; buy <= 1; ++buy) {
                for (int limit = 1; limit <= k; ++limit) {
                    int profit = 0;
                    if (buy) {
                        int buyKaro = -prices[index] + dp[index + 1][0][limit];
                        int skipKaro = dp[index + 1][1][limit];
                        profit = max(buyKaro, skipKaro);
                    } else {
                        int sellKaro = prices[index] + dp[index + 1][1][limit - 1];
                        int skipKaro = dp[index + 1][0][limit];
                        profit = max(sellKaro, skipKaro);
                    }
                    dp[index][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][2];
    }

    int solveSO(int k, vector<int> &prices){
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int> (k + 1, 0));
        vector<vector<int>> next(2, vector<int> (k + 1, 0));

        for (int index = n - 1; index >= 0 ; --index) {
            for (int buy = 0; buy <= 1; ++buy) {
                for (int limit = 1; limit <= k; ++limit) {
                    int profit = 0;
                    if (buy) {
                        int buyKaro = -prices[index] + next[0][limit];
                        int skipKaro = next[1][limit];
                        profit = max(buyKaro, skipKaro);
                    } else {
                        int sellKaro = prices[index] + next[1][limit - 1];
                        int skipKaro = next[0][limit];
                        profit = max(sellKaro, skipKaro);
                    }
                    curr[buy][limit] = profit;
                }
            }
            next = curr;
        }
        return next[1][k];
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
//        return solve(prices, 1, 0, 2);
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (k + 1, -1)));
//        return solveMem(prices, 1,   0, dp, k);
//        return solveTab(k, prices);
        return solveSO(k, prices);
    }
};