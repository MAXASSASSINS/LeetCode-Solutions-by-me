class Solution {
public:
    int solve(int n, vector<int> &cuts, int i, int j){
        if(i > j) return 0;
        
        long long mini = LONG_MAX;
        long long cutSum = 0;
        for(int k = i; k <= j; k++){
            cutSum = 0LL + cuts[j + 1] - cuts[i - 1] + solve(n, cuts, i, k - 1) + solve(n, cuts, k + 1, j);
            mini = min(cutSum, mini);
        }
        
        return (int)mini;
    }
    
    int solveMem(int n, vector<int> &cuts, int i, int j, vector<vector<int>> &dp){
        if(i > j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int mini = INT_MAX;
        int cutSum = 0;
        for(int k = i; k <= j; k++){
            cutSum =  cuts[j + 1] - cuts[i - 1] + solveMem(n, cuts, i, k - 1, dp) + solveMem(n, cuts, k + 1, j, dp);
            mini = min(cutSum, mini);
        }
        
        return dp[i][j] = mini;
    }
    
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        // return solve(n, cuts, 1, cuts.size() - 2);
        
        vector<vector<int>> dp(c + 1, vector<int> (c + 1, -1));
        return solveMem(n, cuts, 1, cuts.size() - 2, dp);
    }
};