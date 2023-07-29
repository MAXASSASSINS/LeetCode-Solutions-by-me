class Solution {
public:
    int solve(vector<int> &nums, int index, int prev){
        if(index == nums.size()) return 0;
        
        
        int excl = solve(nums, index + 1, prev);
        int incl = INT_MIN;
        
        if(prev == -1 || nums[prev] < nums[index]){
            incl = 1 + solve(nums, index + 1, index);
        }
        
        return max(excl, incl);
    }
    
    int solveMem(vector<int> &nums, int index, int prev, vector<vector<int>> &dp){
        if(index == nums.size()) return 0;
        
        if(dp[index][prev + 1] != -1) return dp[index][prev + 1];
        
        int excl = solveMem(nums, index + 1, prev, dp);
        int incl = INT_MIN;
        
        if(prev == -1 || nums[prev] < nums[index]){
            incl = 1 + solveMem(nums, index + 1, index, dp);
        }
        
        return dp[index][prev + 1] = max(excl, incl);
    }
    
    int solveTab(vector<int> &nums){
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        
        for(int index = n - 1; index >= 0; index--){
            for(int prev = index - 1; prev >= -1; prev--){
                int excl = dp[index + 1][prev + 1];
                int incl = INT_MIN;

                if(prev == -1 || nums[prev] < nums[index]){
                    incl = 1 + dp[index + 1][index + 1];
                }

                dp[index][prev + 1] = max(excl, incl);
            }
        }
        
        
        return dp[0][0];
    } 
    
    int solveTab2(vector<int> &nums){
        int n = nums.size();
        vector<int> dp(n, 1);
        
        for(int index = 0; index < n; index++){
            for(int prev = 0; prev < index; prev++){
                if(nums[index] > nums[prev]){
                    dp[index] = max(dp[index], dp[prev] + 1);
                }
            }
        }
        
        int maxi = INT_MIN;
        for(auto x: dp){
            maxi = max(maxi, x);
        }
        
        return maxi;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        // return solve(nums, 0, -1);
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n + 1, -1));
        // return solveMem(nums, 0, -1, dp);
        
        // return solveTab(nums);
        return solveTab2(nums);
        
    }
};