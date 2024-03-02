class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int st = 0;
        int en = nums.size() - 1;
        int i = en;
        vector<int> ans(nums.size());
        while(st <= en) {
            int num1 = abs(nums[st]);
            int num2 = abs(nums[en]);
            if (num1 >= num2) {
                ans[i] = (num1 * num1);
                st++;
            } else {
                ans[i] = (num2 * num2);
                en--;
            }
            i--;
        }
        return ans;
    }
};