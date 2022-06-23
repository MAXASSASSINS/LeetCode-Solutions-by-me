class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 1;
        int length = 1;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if(nums[i] < nums[i + 1]){
                length++;
            }
            else{
                ans = max(length, ans);
                length = 1;
            }
        }
        if(length > 1){
            ans = max(length, ans);
        }
        return ans;
    }
};