class Solution {
public:
    int solve(vector<int> &nums, int diff, int index){
        if (index < 0){
            return 0;
        }
        int ans = 0;
        for (int i = index - 1; i >= 0 ; --i) {
            if (nums[index] - nums[i] == diff){
                ans = max(ans, 1 + solve(nums, diff, i));
            }
        }
        return ans;
    }

    int solveMem(vector<int> &nums, int diff, int index, unordered_map<int,int> dp[]){
        if (index < 0){
            return 0;
        }
        if (dp[index].count(diff)){
            return dp[index][diff];
        }
        int ans = 0;
        for (int i = index - 1; i >= 0 ; --i) {
            if (nums[index] - nums[i] == diff){
                ans = max(ans, 1 + solveMem(nums, diff, i, dp));
            }
        }
        return dp[index][diff] = ans;
    }




    int longestArithSeqLength(vector<int>& nums) {
       int n = nums.size();
        if (n <= 2)
            return n;
        int ans = 0;
        unordered_map<int,int>dp[n + 1];
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = nums[i] - nums[j];
                int cnt = 1;

                if (dp[j].count(diff)){
                    cnt = dp[j][diff];
                }

                dp[i][diff] = 1 + cnt;

                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};