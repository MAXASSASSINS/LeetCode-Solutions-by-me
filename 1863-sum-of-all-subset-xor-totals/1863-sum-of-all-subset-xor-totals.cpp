class Solution {
public:
    void solve(vector<int> &nums, int index, int curr, int &ans){
        if(index >= nums.size()){
            ans += curr;
            return;
        }
        solve(nums, index + 1, curr, ans);
        solve(nums, index + 1, curr ^ nums[index], ans);
    }
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        solve(nums, 0, 0, ans);
        return ans;
    }
};