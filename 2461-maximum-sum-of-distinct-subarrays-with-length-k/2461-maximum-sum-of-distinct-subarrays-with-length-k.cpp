class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res = 0;
        int n = nums.size();
        unordered_map<int, int> m;
        
        long long sum = 0;
        for(int i = 0; i < k; i++){
            m[nums[i]]++;
            sum += nums[i];
        }
        
        if(m.size() == k){
            res = max(res, sum);
        }
        
        for(int i = k; i < n; i++){
            m[nums[i - k]]--;
            if(m[nums[i - k]] == 0){
                m.erase(nums[i - k]);
            }
            
            m[nums[i]]++;
            sum -= nums[i - k];
            sum += nums[i];
            
            if(m.size() == k){
                res = max(res, sum);
            }
        }
        
        return res;
        
        
    }
};