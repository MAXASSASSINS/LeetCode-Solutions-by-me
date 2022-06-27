class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        if (nums.size() == 1){
            return nums;
        }
        int st = 0;
        int en = nums.size() - 1;
        while (st <= en){
            if(nums[st] % 2 == 0){
                st++;
            }
            else if(nums[en] % 2 == 1){
                en--;
            }
            else if(nums[st] % 2 == 1 && nums[en] % 2 == 0){
                swap(nums[st], nums[en]);
                st++;
                en--;
            }
        }
        return nums;
    }
};