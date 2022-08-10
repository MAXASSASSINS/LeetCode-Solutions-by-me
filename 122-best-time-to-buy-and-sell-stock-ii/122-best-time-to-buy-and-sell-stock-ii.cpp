class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int index = 1;
        int n = prices.size();
        int currentPrice = prices[0];
        int sellPrice = prices[0];
        while (index < n){
            while (index < n && prices[index] <= prices[index - 1]) {
                currentPrice = prices[index];
                index++;
            }
            sellPrice = currentPrice;
            while (index < n && prices[index] >= sellPrice) {
                sellPrice = prices[index];
                index++;
            }
            ans += sellPrice - currentPrice;
            currentPrice = prices[index];
        }
        return ans;

    }
};