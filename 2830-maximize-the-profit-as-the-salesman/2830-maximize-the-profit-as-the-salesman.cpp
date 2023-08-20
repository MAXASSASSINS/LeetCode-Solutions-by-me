class Solution {
public:    
    int bs(vector<vector<int>> &offers, int end, int index){
        int low = index;
        int high = offers.size() - 1;
        
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            
            int start = offers[mid][0];
            if(start > end){
                high = mid - 1;
                ans = mid;
            }
            else{
                low = mid + 1;
            }
        }
        
        return ans;
    }
    
    int solve(int n, vector<vector<int>>& offers, int index, vector<int> &dp){
        if(index == offers.size()) return 0;
        
        if(dp[index] != -1) return dp[index];
        
        int excl = solve(n, offers, index + 1, dp);
        
        
        int nextIndex = bs(offers, offers[index][1], index + 1);
        int incl = offers[index][2] + (nextIndex == -1 ? 0 : solve(n, offers, nextIndex, dp));
        
        return dp[index] = max(incl, excl);
    }
    
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end());
        vector<int> dp(offers.size(), -1);
        return solve(n, offers, 0, dp);
    }
};