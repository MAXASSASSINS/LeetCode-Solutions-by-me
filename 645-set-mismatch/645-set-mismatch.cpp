class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        int i = 0;
        while(i < nums.size()) {
            if(nums[i] == i + 1){
                i++;
            }
            else{
                if(nums[nums[i] - 1] == nums[i]){
                    i++;
                }
                else{
                    swap(nums[nums[i] - 1], nums[i]);
                }
            }
        }

        for (int j = 0; j < nums.size(); ++j) {
            if(nums[j] != j + 1){
                ans.push_back(nums[j]);
                ans.push_back(j + 1);
            }
        }
        return ans;
    }
};