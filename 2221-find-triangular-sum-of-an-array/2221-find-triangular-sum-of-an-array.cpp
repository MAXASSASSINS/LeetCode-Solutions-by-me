class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int ans;
        int n = nums.size();
        int i = 0;
        while (i < n - 1) {
            vector<int> temp(nums.size() - 1);
            for (int j = nums.size() - 1; j > 0; --j) {
                temp[j - 1] = (nums[j] + nums[j - 1]) % 10;
            }
            nums.clear();
            nums = temp;
            i++;
        }
        return nums[0];
    }
};