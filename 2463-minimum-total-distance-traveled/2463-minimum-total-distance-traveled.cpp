class Solution {
public:
    long long solve(vector<int>& robot, vector<int>& factory, int robi, int faci, vector<vector<long long>> &dp){
        if(robi >= robot.size()){
            return 0;
        }
        if(faci >= factory.size()){
            return 1e12;
        }
        
        if(dp[robi][faci] != 1e14) return dp[robi][faci];
        
        long long excl = solve(robot, factory, robi, faci + 1, dp);
        long long incl = abs(robot[robi] - factory[faci]) + solve(robot, factory, robi + 1, faci + 1, dp);
        
        return dp[robi][faci] = min(excl, incl);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<int> fact;
        for(auto &f: factory){
            for(int i = 0; i < f[1]; i++){
                fact.push_back(f[0]);
            }
        }
        
        vector<vector<long long>> dp(robot.size(), vector<long long>(fact.size(), 1e14));
        return solve(robot, fact, 0, 0, dp);
    }
};