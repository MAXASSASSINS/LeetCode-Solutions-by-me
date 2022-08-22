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


    int maxSatisfaction(vector<int>& satisfaction) {
        int currans = 0;
        int n = satisfaction.size();
        vector<vector<int>> dp (n + 1, vector<int>(n  + 1, -1));
        sort(satisfaction.begin(), satisfaction.end());

//        return solve(satisfaction, 0, 1);
        return solveMem(satisfaction, 0, 1, dp);

    }
};