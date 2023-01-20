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
    
    
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        sort(pairs.begin(), pairs.end());
        // return solve(pairs, 0, -1);
        return solveMem(pairs, 0, -1, dp);
    }
};