class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        ans.push_back(temp);
        int startIndex = 0;
        int endIndex = 0;
        for (int i = 0; i < nums.size(); ++i) {
            startIndex = 0;
            if (i > 0 && nums[i] == nums[i - 1]) {
                startIndex = endIndex + 1;
            }
            endIndex = ans.size() - 1;
            int n = ans.size();
            for (int j = startIndex; j < n; ++j) {
                vector<int> temp2 = ans.at(j);
                temp2.push_back(nums[i]);
                ans.push_back(temp2);
            }


        }
        return ans;
    }
};