class Solution {
public:
    int solve(int n){
        if(n == 0)
            return 0;
        int ans = n;
        for (int i = 1; i * i <=  n; ++i) {
            int temp = i * i;
            ans = min(ans, 1 + solve(n - temp));
        }
        return ans;
    }


    int solveMem(int n, vector<int> &dp){
        if(n == 0)
            return 0;
        if(dp[n] != -1) {
            return dp[n];
        }
        int ans = n;
        for (int i = 1; i * i <=  n; ++i) {
            int temp = i * i;
            ans = min(ans, 1 + solveMem(n - temp, dp));
        }
        dp[n] = ans;
        return ans;
    }

    int numSquares(int n) {
        vector<int> dp(n + 1, -1);
        return solveMem(n, dp);
//        return solve(n);
    }

};