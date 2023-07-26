class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int ans = INT_MIN;
        
        for(int i = 1; i < prices.size(); i++){
            ans = max(ans, prices[i] - mini);
            mini = min(prices[i], mini);
        }
        
        return ans >= 0 ? ans : 0;
    }
};