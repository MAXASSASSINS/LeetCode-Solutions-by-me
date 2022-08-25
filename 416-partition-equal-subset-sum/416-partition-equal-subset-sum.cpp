class Solution {
public:
    bool solve(vector<int> &nums, int index, int target){
        if(index >= nums.size() || target < 0){
            return false;
        }
        if (target < 0){
            return false;
        }
        if (target == 0)
            return true;
        bool include = solve(nums, index + 1, target - nums[index]);
        bool exclude = solve(nums, index + 1, target - 0);
        return include || exclude;
    }

    bool solveMem(vector<int> &nums, int index, int target, vector<vector<int>> &dp){
        if(index >= nums.size() || target < 0){
            return false;
        }
        if (target < 0){
            return false;
        }
        if (target == 0)
            return true;
        if(dp[index][target] != -1){
            return dp[index][target];
        }
        bool include = solveMem(nums, index + 1, target - nums[index], dp);
        bool exclude = solveMem(nums, index + 1, target - 0, dp);
        return dp[index][target] =  include || exclude;
    }





    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        cout<<sum;
        if(sum % 2 != 0)
            return false;
//        return solve(nums, 0, sum / 2);
        vector<vector<int>> dp (nums.size() + 1, vector<int>(sum / 2 + 1, -1));
        return solveMem(nums, 0, sum/ 2, dp);
    }
};