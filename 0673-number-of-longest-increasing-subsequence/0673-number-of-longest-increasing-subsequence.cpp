class Solution {
public:
    int solveTab2(vector<int> &nums){
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> count(n, 1);
        
        int maxLength = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i; j++){
                if(nums[i] > nums[j]){
                    if(dp[i] < 1 + dp[j]){
                        dp[i] = 1 + dp[j];     
                        count[i] = count[j];
                    }
                    else if(dp[i] == dp[j] + 1){
                        count[i] += count[j];
                    }
                }
            }
            maxLength = max(maxLength, dp[i]);
        }
        
        int numbers = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] == maxLength){
                numbers += count[i];
            }
        }
        
        return numbers;
    }
        
    int findNumberOfLIS(vector<int>& nums) {
        return solveTab2(nums);
    }
};