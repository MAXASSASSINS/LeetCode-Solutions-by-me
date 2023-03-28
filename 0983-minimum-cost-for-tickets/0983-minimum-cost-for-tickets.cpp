class Solution {
public:
    int findIndex(vector<int> &days, int st, int target){
        int i = st;
        while(i < days.size()){
            if(days[i] > target){
                break;
            }
            i++;
        }
        
        return i;
    }
    int solve(vector<int> &days, vector<int> &costs, int index){
        if(index >= days.size()) return 0;
        
        int one = costs[0] + solve(days, costs, index + 1);
        
        int seventhDayIndex = findIndex(days, index, days[index] + 7 - 1);
        int seven = costs[1] + solve(days, costs, seventhDayIndex);
        
        int thirtyDayIndex = findIndex(days, index, days[index] + 30 - 1);
        int thirty = costs[2] + solve(days, costs, thirtyDayIndex);
        
        return min(one, min(seven, thirty));
        
    }
    int solveMem(vector<int> &days, vector<int> &costs, int index, vector<int> &dp){
        if(index >= days.size()) return 0;
        if(dp[index] != -1) return dp[index];
        int one = costs[0] + solveMem(days, costs, index + 1,dp);
        
        int seventhDayIndex = findIndex(days, index, days[index] + 7 - 1);
        int seven = costs[1] + solveMem(days, costs, seventhDayIndex,dp);
        
        int thirtyDayIndex = findIndex(days, index, days[index] + 30 - 1);
        int thirty = costs[2] + solveMem(days, costs, thirtyDayIndex,dp);
        
        return dp[index] = min(one, min(seven, thirty));
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size() + 1, -1);
        int ans = INT_MAX;
        // return solve(days, costs, 0);
        return solveMem(days, costs, 0, dp);
    }
};