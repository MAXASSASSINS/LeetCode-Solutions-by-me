class Solution {
public:
    int solve(vector<int>& nums, int index){
        if(index < 0){
            return 0;
        }
        int include = nums[index] + solve(nums, index - 2);
        int exlcude = 0 + solve(nums, index - 1);

        return max(exlcude, include);
    }

    int solveMem(vector<int>& nums, int index, vector<int> &dp){
        if(index < 0){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        int include = nums[index] + solveMem(nums, index - 2, dp);
        int exlcude = 0 + solveMem(nums, index - 1, dp);

        return dp[index] = max(exlcude, include);
    }

    int solveTab(vector<int> &nums){
        int n = nums.size();
        vector<int> dp(n, 0);

        dp[0] = nums[0];
        for(int i = 1; i < n; i++){
            int include = nums[i]; 
            if(i - 2 >= 0){
                include += dp[i - 2];
            }
            int exlcude = 0;
            if(i - 1 >= 0){
                exlcude += dp[i - 1];
            }

            dp[i] = max(include, exlcude);
        }
        return dp[n - 1];
    }

    
    int rob(vector<int>& nums) {
		int n=nums.size();
		if(n==1)return nums[0];
		vector<int>nums1,nums2;
		for(int i=0;i<n;i++){
			if(i!=0)nums1.push_back(nums[i]);
			if(i!=n-1)nums2.push_back(nums[i]);
		}
		// return max(solve(nums1, n - 2),solve(nums2, n - 2)); 
        // vector<int> first(n, -1);
        // vector<int> second(n, -1);
		// return max(solveMem(nums1, n - 2, first),solveMem(nums2, n - 2, second);

        return max( solveTab(nums1), solveTab(nums2)); 
	}
};