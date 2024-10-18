class Solution {
public:
    int solve(vector<int> &nums, int index, int curr, const int &target){
        if(index >= nums.size()){
            if(curr == target) return 1;
            return 0;
        }
        
        int excl = solve(nums, index + 1, curr, target);
        int incl = solve(nums, index + 1, curr | nums[index], target);
        
        return incl + excl;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int x = 0;
        for(auto num: nums){
            x |= num;
        }
        return solve(nums, 0, 0, x);
    }
};