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

    int solveTab(string &a, string &b){
        int n = a.length();
        int m = b.length();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        for (int i = 0; i < m + 1; ++i) {
            dp[n][i] = m - i;
        }
        for (int i = 0; i < n + 1; ++i) {
            dp[i][m] = n - i;
        }

        for (int i = n - 1; i >= 0 ; --i) {
            for (int j = m - 1; j >= 0; --j) {
                int ans = 0;
                if (a[i] == b[j]) {
                    ans = dp[i + 1][j + 1];
                } else {
                    //insert
                    int insertChar = 1 + dp[i][j + 1];

                    //delete
                    int deleteChar = 1 + dp[i + 1][j];

                    //replace
                    int replaceChar = 1 + dp[i + 1][j + 1];
                    ans = min(insertChar, min(deleteChar, replaceChar));
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int solveSO(string &a, string &b){
        int n = a.length();
        int m = b.length();
        vector<int> curr(m + 1, 0);
        vector<int> next(m + 1, 0);

        for (int i = 0; i < m + 1; ++i) {
            next[i] = m - i;
        }

        for (int i = n - 1; i >= 0 ; --i) {
            for (int j = m - 1; j >= 0; --j) {
                //catch is here
                curr[m] = n - i;


                int ans = 0;
                if (a[i] == b[j]) {
                    ans = next[j + 1];
                } else {
                    //insert
                    int insertChar = 1 + curr[j + 1];

                    //delete
                    int deleteChar = 1 + next[j];

                    //replace
                    int replaceChar = 1 + next[j + 1];
                    ans = min(insertChar, min(deleteChar, replaceChar));
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }

    int minDistance(string word1, string word2) {
        if (word1.length() == 0)
            return word2.length();
        if (word2.length() == 0)
            return word1.length();
//        return solve(word1, word2, 0, 0);
//        vector<vector<int>> dp(word1.size() + 1, vector<int> (word2.size() + 1, -1));
//        return solveMem(word1,word2, 0, 0, dp);
//        return solveTab(word1, word2);
        return solveSO(word1, word2);
    }
};