class Solution {
public:
    int solve(vector<vector<int>> &pairs, int index, int prev){
        if(index >= pairs.size()) return 0;
        
        // exlucde 
        int excl = solve(pairs, index + 1, prev);
        
        // include
        int incl = 0;
        if(prev == -1 || pairs[index][0] > pairs[prev][1]){
            incl = 1 + solve(pairs, index + 1, index);            
        }
        
        return max(incl, excl);
        
    }
    
    int solveMem(vector<vector<int>> &pairs, int index, int prev, vector<vector<int>> &dp){
        if(index >= pairs.size()) return 0;
        
        if(dp[index][prev + 1] != -1){
            return dp[index][prev + 1];
        }
        
        // exlucde 
        int excl = solveMem(pairs, index + 1, prev, dp);
        
        // include
        int incl = 0;
        if(prev == -1 || pairs[index][0] > pairs[prev][1]){
            incl = 1 + solveMem(pairs, index + 1, index, dp);       
        }
        return dp[index][prev + 1] = max(incl, excl);
        
    }
    
    
//     int solveTab(vector<vector<int>> &pairs){
//         int n = pairs.size();
//         vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));
//         for(int i = n - 1; i >= 0; i++){
//             for(int prev = i - 1; prev >= -1; prev++){
//                 // exlucde 
//                  int excl = solveMem(pairs, index + 1, prev, dp);
        
//                 // include
//                 int incl = 0;
//                 if(prev == -1 || pairs[index][0] > pairs[prev][1]){
//                     incl = 1 + dp[i + 1][prev + 1];       
//                 }
//                 dp[i][prev + 1] = max(incl, excl);
//         }
        
//     }
        
//         return 0;
//     }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        sort(pairs.begin(), pairs.end());
        // return solve(pairs, 0, -1);
        return solveMem(pairs, 0, -1, dp);
    }
};