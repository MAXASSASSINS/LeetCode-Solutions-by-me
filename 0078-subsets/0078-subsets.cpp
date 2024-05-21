class Solution {
public:
    void solve(vector<int> &nums, vector<int> &temp, int index, vector<vector<int>> &ans){
        if(index >= nums.size()){
            ans.push_back(temp);
            return;
        }
        
        solve(nums, temp, index + 1, ans);
        temp.push_back(nums[index]);
        solve(nums, temp, index + 1, ans);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums, temp, 0, ans);
        return ans;
    }
};