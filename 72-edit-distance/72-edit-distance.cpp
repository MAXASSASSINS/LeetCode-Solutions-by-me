class Solution {
public:
    int solve(string &a, string &b, int i, int j) {
        if (i == a.length()) {
            return b.length() - j;
        }
        if (j == b.length()) {
            return a.length() - i;
        }
        int ans = 0;

        if (a[i] == b[j]) {
            return solve(a, b, i + 1, j + 1);
        } else {
            //insert
            int insertChar = 1 + solve(a, b, i, j + 1);

            //delete
            int deleteChar = 1 + solve(a, b, i + 1, j);

            //replace
            int replaceChar = 1 + solve(a, b, i + 1, j + 1);
            ans = min(insertChar, min(deleteChar, replaceChar));
        }
        return ans;
    }

    int solveMem(string &a, string &b, int i, int j, vector<vector<int>> &dp) {
        if (i == a.length()) {
            return b.length() - j;
        }
        if (j == b.length()) {
            return a.length() - i;
        }
        if (dp[i][j] != -1)
            return dp[i][j];


        int ans = 0;

        if (a[i] == b[j]) {
            return solveMem(a, b, i + 1, j + 1, dp);
        } else {
            //insert
            int insertChar = 1 + solveMem(a, b, i, j + 1, dp);

            //delete
            int deleteChar = 1 + solveMem(a, b, i + 1, j, dp);

            //replace
            int replaceChar = 1 + solveMem(a, b, i + 1, j + 1, dp);
            ans = min(insertChar, min(deleteChar, replaceChar));
        }
        return dp[i][j] = ans;
    }


    int minDistance(string word1, string word2) {
//        return solve(word1, word2, 0, 0);
        vector<vector<int>> dp(word1.size() + 1, vector<int> (word2.size() + 1, -1));
        return solveMem(word1,word2, 0, 0, dp);
    }
};