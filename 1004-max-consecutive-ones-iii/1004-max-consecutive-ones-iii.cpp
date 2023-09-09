class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int j = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                k--;
            }
            if(k < 0){
                while(nums[j] != 0){
                    j++;
                }
                j++;
                k = 0;
            }
            ans = max(ans, i - j + 1);
        }
        
        return ans;
    }
};