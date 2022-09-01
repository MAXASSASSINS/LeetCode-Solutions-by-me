class Solution {
public:
    int solve(int k, vector<int> &prices, int operationNo, int index){
        if (index == prices.size()){
            return 0;
        }
        if(operationNo == 2 * k){
            return 0;
        }
        int ans = 0;
        if (operationNo % 2 == 0){
            int buyKaro = -prices[index]  + solve(k, prices, operationNo + 1, index + 1);
            int skipKaro = solve(k, prices, operationNo, index + 1);
            ans = max(buyKaro, skipKaro);
        }
        else{
            int sellKaro = prices[index]  + solve(k, prices, operationNo + 1, index + 1);
            int skipKaro = solve(k, prices, operationNo, index + 1);
            ans = max(sellKaro, skipKaro);
        }
        return ans;
    }

    int solveMem(int k, vector<int> &prices, int operationNo, int index, vector<vector<int>> &dp){
        if (index == prices.size()){
            return 0;
        }
        if(operationNo == 2 * k){
            return 0;
        }
        if (dp[index][operationNo] != -1){
            return dp[index][operationNo];
        }
        int ans = 0;
        if (operationNo % 2 == 0){
            int buyKaro = -prices[index]  + solveMem(k, prices, operationNo + 1, index + 1, dp);
            int skipKaro = solveMem(k, prices, operationNo, index + 1, dp);
            ans = max(buyKaro, skipKaro);
        }
        else{
            int sellKaro = prices[index]  + solveMem(k, prices, operationNo + 1, index + 1, dp);
            int skipKaro = solveMem(k, prices, operationNo, index + 1, dp);
            ans = max(sellKaro, skipKaro);
        }
        return dp[index][operationNo] = ans;
    }

    int solveTab(int k, vector<int> &prices){
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int> (2 * k + 1, 0));

        for (int index = n - 1; index >= 0; --index) {
            for (int operationNo = 0; operationNo < 2 * k; ++operationNo) {
                int ans = 0;
                if (operationNo % 2 == 0){
                    int buyKaro = -prices[index]  + dp[index + 1][operationNo + 1];
                    int skipKaro = dp[index + 1][operationNo];
                    ans = max(buyKaro, skipKaro);
                }
                else{
                    int sellKaro = prices[index]  + dp[index + 1][operationNo + 1];
                    int skipKaro = dp[index + 1][operationNo];
                    ans = max(sellKaro, skipKaro);
                }
                dp[index][operationNo] = ans;
            }
        }
        return dp[0][0];
    }

    int maxProfit(int k, vector<int>& prices) {
//        return solve(k, prices, 0, 0);
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int> (2 * k, -1));
//        return solveMem(k, prices, 0, 0, dp);
        return solveTab(k, prices);
    }
};