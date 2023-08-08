class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int ans = -1;
        int n = prices.size();
        if(n <= 1) return 0;
        for(int i = 1; i < n; i++){
            mini = min(mini, prices[i]);
            ans = max(ans, prices[i] - mini);
        }
        
        return ans;
    }
};