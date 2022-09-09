class Solution {
public:
    void solve(vector<int>& nums, int target, int index, int currSum, int &ans){
        if (index >= nums.size()){
            if (currSum == target){
                ans += 1;
            }
            return;
        }
        solve(nums, target, index + 1, currSum + nums[index], ans);
        solve(nums, target, index + 1, currSum - nums[index], ans);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0;
        solve(nums, target, 0, 0, ans);
        return ans;
    }
};