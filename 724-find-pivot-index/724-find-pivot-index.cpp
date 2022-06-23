class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int low = 0;
        int ans = -1;
        int high = nums.size() - 1;
        int leftSum = 0;
        int rightSum = 0;
        while (low <= high){
            if(low == 0){
                for (int i = 1; i <= high; ++i) {
                    rightSum += nums[i];
                }
                if(leftSum == rightSum){
                    return 0;
                }
                low++;
                continue;
            }
            leftSum += nums[low - 1];
            rightSum -= nums[low];
            if(leftSum == rightSum){
                ans = low;
                break;
            }
            low++;
        }
        return ans;
    }
};