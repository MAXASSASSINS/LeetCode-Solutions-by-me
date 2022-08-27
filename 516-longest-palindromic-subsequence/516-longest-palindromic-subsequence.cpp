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

    int longestCommonSubsequence(string text1, string text2) {
//        return solve(text1, text2, 0, 0);
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return solveMem(text1, text2, 0, 0, dp);
//        return solveTab(text1, text2);
//        return solveSO(text1, text2);
    }

    int longestPalindromeSubseq(string s) {
        string t = s;
        std::reverse(s.begin(), s.end());
        return longestCommonSubsequence(s, t);
    }
};