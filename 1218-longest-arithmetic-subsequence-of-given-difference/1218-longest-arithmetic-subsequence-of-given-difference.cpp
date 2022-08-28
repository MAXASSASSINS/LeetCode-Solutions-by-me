class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int, int> dp;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int temp = arr[i] - difference;
            int tempLength = 0;
            if(dp.count(temp)){
                tempLength = dp[temp];
            }
            dp[arr[i]] = 1 + tempLength;

            ans = max(ans, dp[arr[i]]);
        }

        return ans;
    }
};