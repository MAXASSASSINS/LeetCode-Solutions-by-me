class Solution {
public:
    int solve(string s1, string s2, int i, int j){
       if(i == 0 || j == 0) return 0;
        
        if(s1[i - 1] == s2[j - 1]){
            return s1[i - 1] + solve(s1, s2, i - 1, j - 1);
        }
        else{
            return max(solve(s1, s2, i - 1, j), solve(s1, s2, i, j - 1));
        }
    }
    
    
    int solveTab(string s1, string s2){
        int n = s1.length();
        int m = s2.length();
        
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = s1[i - 1] + dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = max(dp[i - 1][j],  dp[i][j - 1]);
                }
            }
        }        
        return dp[n][m];
    }
    int minimumDeleteSum(string s1, string s2) {
        // int LCSSum = solve(s1, s2, s1.length(), s2.length());
        
        
        int LCSSum = solveTab(s1, s2);
        
        int s1Sum = 0;
        for(auto c:s1){
            s1Sum += c;
        }
        
        int s2Sum = 0;
        for(auto c:s2){
            s2Sum += c;
        }
        
        return s1Sum + s2Sum - 2 * LCSSum;
        
    }
};