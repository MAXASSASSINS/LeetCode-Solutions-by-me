class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() < 5) return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int diff1 = nums[n - 4] - nums[0];
        int diff2 = nums[n - 1] - nums[3];
        int diff3 = nums[n - 2] - nums[2];
        int diff4 = nums[n - 3] - nums[1];
        
        int mini = min(diff1, min(diff2, min(diff3, diff4)));
        return mini;
    }
};