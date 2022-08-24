class Solution {
public:
    int solve(vector<int> &slices, int index,int endingIndex, int slicesToEat) {
        if(slicesToEat == 0 || index > endingIndex)
            return 0;
        int include = slices[index] + solve(slices, index + 2, endingIndex, slicesToEat - 1);
        int exclude = 0 + solve(slices, index + 1, endingIndex, slicesToEat);
        return max(include, exclude);
    }

    int solveMem(vector<int> &slices, int index,int endingIndex, int slicesToEat, vector<vector<int>> &dp){
        if(slicesToEat == 0 || index > endingIndex)
            return 0;

        if(dp[index][slicesToEat] != -1){
            return dp[index][slicesToEat];
        }
        int include = slices[index] + solveMem(slices, index + 2, endingIndex, slicesToEat - 1, dp);
        int exclude = 0 + solveMem(slices, index + 1, endingIndex, slicesToEat, dp);
        return dp[index][slicesToEat] =  max(include, exclude);
    }

    int solveTab(vector<int> &slices){
        int k = slices.size();
        vector<vector<int>> dp1(k + 2, vector<int>(k + 2, 0));
        vector<vector<int>> dp2(k + 2, vector<int>(k + 2, 0));

        for (int index = k -2 ; index >= 0 ; --index) {
            for (int slicesToEat = 1; slicesToEat <= k/3; ++slicesToEat) {
                int include = slices[index] + dp1[index + 2][slicesToEat - 1];
                int exclude = dp1[index + 1][slicesToEat];
                dp1[index][slicesToEat] =  max(include, exclude);
            }
        }

        for (int index = k - 1 ; index >= 1 ; --index) {
            for (int slicesToEat = 1; slicesToEat <= k/3; ++slicesToEat) {
                int include = slices[index] + dp2[index + 2][slicesToEat - 1];
                int exclude = dp2[index + 1][slicesToEat];
                dp2[index][slicesToEat] =  max(include, exclude);
            }
        }

        return max(dp1[0][k/3], dp2[1][k/3]);


    }

    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
//        int case1 = solve(slices, 0, k - 2, k / 3);
//        int case2 = solve(slices, 1, k - 1, k / 3);
//        return max(case1, case2);
//        vector<vector<int>> dp1(k, vector<int>(k, -1));
//        vector<vector<int>> dp2(k, vector<int>(k, -1));
//        int case1 = solveMem(slices, 0, k - 2, k / 3, dp1);
//        int case2 = solveMem(slices, 1, k - 1, k / 3, dp2);
//        return max(case1, case2);

        return solveTab(slices);

    }
};