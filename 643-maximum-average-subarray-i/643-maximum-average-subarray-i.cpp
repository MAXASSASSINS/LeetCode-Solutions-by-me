class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double ans = INT_MIN;
        double sum = 0;
        for (int i = 0; i <= n - k; ++i) {
            if(i == 0){
                for (int j = 0; j < k; ++j) {
                    sum += nums[j];
                }
                ans = max(sum, ans);
                continue;
            }
            sum -= nums[i - 1];
            sum += nums[i + k - 1];
            ans = max(sum , ans);
        }
        ans /= k;
        return ans;
    }
};