class Solution {
public:
    int solve(vector<vector<int>> &events, int k, int idx, int prevEndTime){
        if(idx >= events.size() || k == 0) return 0;
        
        int exclude = solve(events, k, idx + 1, prevEndTime);
        int include = 0;
        
        int startTime = events[idx][0];
        int endTime = events[idx][1];
        int value = events[idx][2];
        

        int i;
        for(i = idx + 1; i < events.size(); i++){
            if(events[i][0] > endTime){
                break;
            }
        }
        include = value + solve(events, k - 1, i, endTime);
        
        return max(include, exclude);
    }
    
    
    int findNext(vector<vector<int>> &events, int st, int en, int target){
        
        while(st <= en){
            int mid = st + (en - st)/2;
            int val = events[mid][0];
            
            if(val > target){
                en = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        
        return st;
        
    }
    
    int solveMem(vector<vector<int>> &events, int k, int idx, int prevEndTime, vector<vector<int>> &dp){
        if(idx >= events.size() || k == 0) return 0;
        
        if(dp[idx][k] != -1) return dp[idx][k];
        
        int exclude = solveMem(events, k, idx + 1, prevEndTime, dp);
        int include = 0;
        
        int startTime = events[idx][0];
        int endTime = events[idx][1];
        int value = events[idx][2];
        
        int i;
        for(i = idx + 1; i < events.size(); i++){
            if(events[i][0] > endTime){
                break;
            }
        }
        include = value + solveMem(events, k - 1, i, endTime, dp);
        
        return dp[idx][k] = max(include, exclude);
    }
    
    
    
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        // return solve(events, k, 0, -1);   
        
        vector<vector<int>> dp(events.size() + 1, vector<int>(k + 1, -1));
        return solveMem(events, k, 0, -1, dp);
    }
};