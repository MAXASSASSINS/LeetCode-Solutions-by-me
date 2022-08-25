class Solution {

public:
    int modulo = 1e9 + 7;
    int solve(int dice, int faces, int target){
        if(target < 0)
            return 0;
        if (dice == 0 && target != 0){
            return 0;
        }
        if (target == 0 && dice != 0)
            return 0;
        if (dice == 0 && target == 0)
            return 1;

        int ans = 0;
        for (int i = 1; i <= faces; ++i) {
            ans = (ans % modulo) + (solve(dice - 1, faces, target - i) % modulo);
        }
        return ans;
    }

    int solveMem(int dice, int faces, int target, vector<vector<int>> &dp){
        if(target < 0)
            return 0;
        if (dice == 0 && target != 0){
            return 0;
        }
        if (target == 0 && dice != 0)
            return 0;
        if (dice == 0 && target == 0)
            return 1;

        if(dp[dice][target] != -1)
            return dp[dice][target];

        int ans = 0;
        for (int i = 1; i <= faces; ++i) {
            ans = (ans % modulo) + (solveMem(dice - 1, faces, target - i, dp) % modulo);
            dp[dice][target] = ans % modulo;
        }
        return dp[dice][target];
    }


    int solveTab(int d, int f, int t){
        vector<vector<int>>dp(d + 1, vector<int>(t + 1, 0));
        dp[0][0] = 1;
        for (int dice = 1; dice <= d ; ++dice) {
            for (int target = 1; target <= t; ++target) {
                int ans = 0;
                for (int i = 1; i <= f; ++i) {
                    if(target - i >= 0){
                        ans = (ans + dp[dice - 1][target - i]) % modulo;
                    }
                }
                dp[dice][target] = ans % modulo;
            }
        }
        return dp[d][t];
    }
    
    
    int numRollsToTarget(int n, int k, int target) {
//        return solve(n, k , target);
//        vector<vector<int>>dp(n + 1, vector<int>(target + 1, -1)) ;
//        return solveMem(n, k, target, dp);
        return solveTab(n, k, target);
    }
};