class Solution {
public:
    bool solve(vector<int> &nums, int index){
        if(index < 0){
            return true;
        }
        
        bool twoEqual = false;
        bool threeEqual = false;
        bool threeIncreasing = false;
        
        if(index > 0 && nums[index] == nums[index - 1]){
            twoEqual = solve(nums, index - 2);
        }
        
        if(index > 1 && nums[index] == nums[index - 1] && nums[index] == nums[index - 2]){
            threeEqual = solve(nums, index - 3);
        }
        
        if(index > 1 && nums[index] == nums[index - 1] + 1 && nums[index - 1] == nums[index - 2] + 1){
            threeIncreasing = solve(nums, index - 3);
        }
        
        return twoEqual || threeEqual || threeIncreasing;
        
    }
    
    bool solveMem(vector<int> &nums, int index, vector<int> &dp){
        if(index < 0){
            return true;
        }
        
        if(dp[index] != -1) return dp[index];
        
        bool twoEqual = false;
        bool threeEqual = false;
        bool threeIncreasing = false;
        
        if(index > 0 && nums[index] == nums[index - 1]){
            twoEqual = solveMem(nums, index - 2, dp);
        }
        
        if(index > 1 && nums[index] == nums[index - 1] && nums[index] == nums[index - 2]){
            threeEqual = solveMem(nums, index - 3, dp);
        }
        
        if(index > 1 && nums[index] == nums[index - 1] + 1 && nums[index - 1] == nums[index - 2] + 1){
            threeIncreasing = solveMem(nums, index - 3, dp);
        }
        
        return dp[index] = twoEqual || threeEqual || threeIncreasing;
        
    }
    
    bool solveTab(vector<int> &nums){
        int n = nums.size();
        vector<int> dp(n + 1);
        
        dp[0] = 1;
        
        for(int index = 1; index < n; index++){
            bool twoEqual = false;
            bool threeEqual = false;
            bool threeIncreasing = false;

            if(index > 0 && nums[index] == nums[index - 1]){
                twoEqual = dp[index - 1];
            }

            if(index > 1 && nums[index] == nums[index - 1] && nums[index] == nums[index - 2]){
                threeEqual = dp[index - 2];
            }

            if(index > 1 && nums[index] == nums[index - 1] + 1 && nums[index - 1] == nums[index - 2] + 1){
                threeIncreasing = dp[index - 2];
            }

            dp[index + 1] = twoEqual || threeEqual || threeIncreasing;
        }
        return dp[n];
    }
    
    
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        // return solve(nums, n - 1);
        
        // vector<int> dp(n, -1);
        // return solveMem(nums, n - 1, dp);
        
        return solveTab(nums);
    }
};