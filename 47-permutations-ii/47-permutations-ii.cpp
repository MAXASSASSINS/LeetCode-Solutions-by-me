class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        unordered_map<int, int> counter;
        for(auto x: nums){
            ++counter[x];
        }
        helper(nums, ans, curr, counter);
        
        return ans;
    }

    void helper(const vector<int> &nums, vector<vector<int>> &ans, vector<int> &curr, unordered_map<int, int> counter) {
        if(curr.size() == nums.size()){
            ans.push_back(curr);
            return;
        }

        for(auto [key, value] : counter){
            if(value == 0) continue;
            curr.push_back(key);
            --counter[key];
            helper(nums, ans, curr, counter);
            curr.pop_back();
            ++counter[key];
        }
        
    }
};