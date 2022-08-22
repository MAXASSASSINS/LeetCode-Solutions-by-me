
class Solution {
public:
    int solve(vector<int>& satisfaction, int index, int dishNumber){
        if(index == satisfaction.size()){
            return 0;
        }

        int include = satisfaction[index] * dishNumber + solve(satisfaction, index + 1, dishNumber + 1);
        int exclude = 0 + solve(satisfaction, index + 1, dishNumber);
        return max(include , exclude);
    }

    int solveMem(vector<int> &satisfaction, int index, int dishNumber, vector<vector<int>> &dp) {
        if(index == satisfaction.size()){
            return 0;
        }
        if(dp[index][dishNumber] != -1){
            return dp[index][dishNumber];
        }
        int include = satisfaction[index] * dishNumber + solveMem(satisfaction, index + 1, dishNumber + 1, dp);
        int exclude = 0 + solveMem(satisfaction, index + 1, dishNumber, dp);
        dp[index][dishNumber] = max(include, exclude);
        return dp[index][dishNumber];
    }

    int solveTab(vector<int> &satisfaction) {
        int n = satisfaction.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int index = n - 1; index >= 0; --index) {
            for (int dishNumber = index; dishNumber >= 0; --dishNumber) {
                int include = satisfaction[index] * (dishNumber + 1) + dp[index + 1][dishNumber + 1];
                int exclude = 0 + dp[index + 1][dishNumber];
                dp[index][dishNumber] = max(include, exclude);
            }
        }
        return dp[0][0];
    }


    int maxSatisfaction(vector<int>& satisfaction) {
        int currans = 0;
        int n = satisfaction.size();
        vector<vector<int>> dp (n + 1, vector<int>(n  + 1, -1));
        sort(satisfaction.begin(), satisfaction.end());

//        return solve(satisfaction, 0, 1);
//        return solveMem(satisfaction, 0, 1, dp);
        return solveTab(satisfaction);
    }
};