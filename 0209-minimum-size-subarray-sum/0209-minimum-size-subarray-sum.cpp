class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int h = 0;
        int currSum = 0;
        int n = nums.size();
        int ans = INT_MAX;
        
        while(h < n){
            currSum += nums[h];
            while(currSum >= target){
                ans = min(ans, h - l + 1);
                currSum -= nums[l];
                l++;
            }
            h++;
        }
        
        return ans == INT_MAX ? 0 : ans;
    }
};