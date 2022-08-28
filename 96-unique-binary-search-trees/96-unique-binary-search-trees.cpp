class Solution {
public:
    int solveMem(int n, vector<int> &dp){
        if(n <= 1)
            return 1;
        if (dp[n] != -1){
            return dp[n];
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans += solveMem(n - i, dp) * solveMem(i - 1, dp);
        }
        return dp[n] = ans;
    }

    int solveTab(int n){
        vector<int> dp (n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

//        i---> number of nodes
        for (int i = 2; i <= n ; ++i) {
            int ans = 0;
//           j----> root node
            for (int j = 1; j <= i; ++j) {
                ans += dp[i - j] * dp[j - 1];
            }
            dp[i] = ans;
        }

        return dp[n];

    }
    int numTrees(int n) {
        vector<int> dp(n + 1, -1);
//        return solveMem(n, dp);
        return solveTab(n);
    }
};