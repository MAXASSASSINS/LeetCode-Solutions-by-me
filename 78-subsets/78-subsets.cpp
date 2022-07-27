class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        ans.push_back(temp);
        for (int i = 0; i < nums.size(); ++i) {
            int n = ans.size();
            for (int j = 0; j < n; ++j) {
                vector<int> temp2 = ans[j];
                temp2.push_back(nums[i]);
                ans.push_back(temp2);
            }
        }
        return ans;
    }
};