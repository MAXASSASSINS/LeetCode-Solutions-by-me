class Solution {
public:
    int solveMem(string &text1, string &text2, int i, int j, vector<vector<int>> &dp){
        if (i == text1.length() || j == text2.length()){
            return 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int include = 0;
        int exclude = 0;
        if (text1[i] == text2[j]){
            include = 1 + solveMem(text1, text2, i + 1, j + 1, dp);
        }
        else{
            exclude = max(solveMem(text1, text2, i + 1, j, dp), solveMem(text1, text2, i, j + 1, dp));
        }
        return dp[i][j] = max(include, exclude);
    }

    int solveTab(string &text1, string &text2) {
        vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));
        for (int i = text1.length() - 1; i >= 0; --i) {
            for (int j = text2.length() - 1; j >= 0; --j) {
                int include = 0;
                int exclude = 0;
                if (text1[i] == text2[j]) {
                    include = 1 + dp[i + 1][j + 1];
                } else {
                    exclude = max(dp[i + 1][j], dp[i][j + 1]);
                }
                dp[i][j] = max(include, exclude);
            }
        }

        return dp[0][0];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
//        return solve(text1, text2, 0, 0);
        // vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
//        return solveMem(text1, text2, 0, 0, dp);
        return solveTab(text1, text2);
//        return solveSO(text1, text2);
    }

    int longestPalindromeSubseq(string s) {
        string t = s;
        std::reverse(s.begin(), s.end());
        return longestCommonSubsequence(s, t);
    }
};