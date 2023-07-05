class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int low = 0;
        int high = 0;
        int n = nums.size();
        
        int count = 0;
        
        int k = 1;
        
        while(high < n){
            if(nums[high] == 0){
                k--;
                while(k < 0 && nums[low] != 0){
                    low++;
                }
                if(k < 0){
                    low++;
                    k++;
                } 
            }
            count = max(count, high - low + 1);
            high++;
        }
        
        return count - 1;
    }
};