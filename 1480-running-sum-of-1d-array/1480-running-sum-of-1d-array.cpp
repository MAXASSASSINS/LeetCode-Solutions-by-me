class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            if(i == 0){
                ans.at(i) = nums.at(i);
                continue;
            }
            ans.at(i) = ans.at(i - 1) + nums.at(i);
        }
        return ans;
    }
};