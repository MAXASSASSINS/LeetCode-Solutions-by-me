class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sums;
        int mod = 1e9 + 7;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                sum %= mod;
                sums.push_back(sum);
            }
        }
        
        sort(sums.begin(), sums.end());
        
        int ans = 0;
        for(int i = left - 1; i <= right - 1; i++){
            ans += sums[i];
            ans %= mod;
        }
        return ans;
    }
};