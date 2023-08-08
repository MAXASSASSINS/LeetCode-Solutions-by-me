class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();
        
        int maxi = *max_element(nums.begin(), nums.end());
        
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(sum < 0){
                sum = 0;
            }
            ans = max(ans, sum);
        }
        
        return ans == 0 ? maxi : ans;
    }
};