class Solution {
public:
    bool solve(int n, int k, vector<int> &arr, int index){
        if(k == 0) return true;

        if(index == 0){
            return arr[0] == k;
        }

        bool excl = solve(n, k, arr, index - 1);
        bool incl = false;
        if(k >= arr[index])
            incl = solve(n, k - arr[index], arr, index - 1);

        return incl || excl;
    }

    bool solveMem(int n, int k, vector<int> &arr, int index, vector<vector<int>> &dp){
        if(k == 0) return true;

        if(index == 0){
            return arr[0] == k;
        }

        if(dp[index][k] != -1) return dp[index][k];

        bool excl = solveMem(n, k, arr, index - 1, dp);
        bool incl = false;
        if(k >= arr[index])
            incl = solveMem(n, k - arr[index], arr, index - 1, dp);

        return dp[index][k] = incl | excl;
    }

    bool solveTab(int n, int k, vector<int> &arr){
        vector<vector<bool>> dp(n + 1, vector<bool>(k + 1));

        for(int i = 0; i < n; i++){
            dp[i][0] = true;
        }
        if(arr[0] <= k) dp[0][arr[0]] = true; 

        for(int index = 1; index < n; index++){
            for(int target = 1; target <= k; target++){
                bool excl = dp[index - 1][target];
                bool incl = false;
                if(target >= arr[index])
                    incl = dp[index - 1][target - arr[index]];

                dp[index][target] = incl | excl;
            }
        }

        return dp[n - 1][k];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto x: nums) sum += x;
        
        int n = nums.size();
        
        if(sum % 2 == 1) return false;
        
        
        int target = sum / 2;
        
        // return solve(n, target, nums, n - 1);
        
        // vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        // return solveMem(n, target, nums, n - 1, dp);
        
        return solveTab(n, target, nums);
    }
};