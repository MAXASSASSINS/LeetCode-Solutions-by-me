class Solution {
public:
    void helper(const vector<int> &nums, vector<vector<int>> &ans, vector<bool> &isVisited, vector<int> &temp){
        if(temp.size() == nums.size()){
            auto it = std::find(ans.begin(), ans.end(),temp);
            if(it == ans.end()){
                ans.push_back(temp);
            }
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if(!isVisited.at(i)){
                temp.push_back(nums.at(i));
                isVisited.at(i) = true;
                helper(nums, ans, isVisited, temp);
                temp.pop_back();
                isVisited.at(i) = false;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> isVisited(nums.size(), false);
        vector<int> temp;
        helper(nums, ans, isVisited, temp);

        return ans;
    }
};