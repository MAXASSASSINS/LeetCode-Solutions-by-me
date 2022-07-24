class Solution {
public:
    void helper(const vector<int> &nums, vector<vector<int>> &ans, vector<int> temp){
        if(temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            int n = nums.at(i);
            if(temp.empty()){
                temp.push_back(n);
                helper(nums, ans, temp);
                temp.pop_back();
                continue;
            }
            auto it = find(temp.begin(), temp.end(), n);
            if(it == temp.end()){
                temp.push_back(n);
            }
            else{
                continue;
            }
            helper(nums, ans, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(nums, ans, temp);
        return ans;
    }
};