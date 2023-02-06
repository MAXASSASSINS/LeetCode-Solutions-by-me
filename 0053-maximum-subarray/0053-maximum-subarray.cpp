class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] + sum > 0){
                sum += nums[i];
                maxSum = max(maxSum, sum);
            }
            else{
                sum = 0;
            }
        }
        if(sum == 0){
            for(int i = 0; i < n; i++){
                maxSum = max(maxSum, nums[i]);
            }
        }

        return maxSum;
        
    }
};