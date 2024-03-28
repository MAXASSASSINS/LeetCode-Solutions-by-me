class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int n = nums.size();
        int ans = 0;
        unordered_map<int,int> m;
        
        while(j < n){
            m[nums[j]]++;
            while(i < j && m[nums[j]] > k){
                m[nums[i]]--;
                i++;
            }
            j++;
            ans = max(ans, j - i);
        }
        
        return ans;  
    }
};