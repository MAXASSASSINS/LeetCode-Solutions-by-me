class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        int res = 1;
        
        for(int i = 0; i < n; i++){
            if(nums[i] == maxi){
                int count = 0;
                while(i < n && nums[i] == maxi){
                    count++;
                    i++;
                }
                res = max(res, count);
            }
        }
        
        return res;
    }
};