class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int ans = -1;
        int j = 0;
        int n = nums.size();
        
        int total = 0;
        for(auto k: nums) total += k;
        
        int sum = total - x;
        
        long long curr = 0;
        for(int i = 0; i < nums.size(); i++){
            curr += nums[i];
            while(j <= i && curr > sum){
                curr -= nums[j];
                j++;
            }
            if(curr == sum) ans = max(i - j + 1, ans);
        }
        
        if(ans == -1) return -1;
        return n - ans;
    }
};