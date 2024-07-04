class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        bool allNegatives = true;
        for(auto x: nums){
            if(x > 0) allNegatives = false;
            ans = max(ans, x);
        }        
        if(allNegatives) return ans;

        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(sum < 0) sum = 0;
            ans = max(ans, sum);
        }   
        return ans;
    }
};