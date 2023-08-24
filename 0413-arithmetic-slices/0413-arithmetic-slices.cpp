class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;
        int ans = 0;
        int count = 0;
        for(int i = 2; i < nums.size(); i++){
            if(nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]){
                count++;
                ans += count;
            }
            else{
                count = 0;
            }
        }
        return ans;
    }
};