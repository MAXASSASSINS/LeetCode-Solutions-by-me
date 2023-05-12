class Solution {
public:
    long long solve(vector<vector<int>> &questions, int index){
        if(index >= questions.size()){
            return 0;
        }    
        
        long long excl = solve(questions, index + 1);
        long long incl = questions[index][0] + solve(questions, index + questions[index][1] + 1);
        
        return max(excl, incl);
        // return 0;
    }
    
    long long solveMem(vector<vector<int>> &questions, int index, vector<long long> &dp){
        if(index >= questions.size()){
            return 0;
        }    
        
        if(dp[index] != -1) return dp[index];
        
        long long excl = solveMem(questions, index + 1, dp);
        long long incl = questions[index][0] + solveMem(questions, index + questions[index][1] + 1, dp);
        
        return dp[index] =  max(excl, incl);
        // return 0;
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        // return solve(questions, 0);
        
        vector<long long> dp(questions.size() + 1, -1);
        return solveMem(questions, 0, dp);
    }
};