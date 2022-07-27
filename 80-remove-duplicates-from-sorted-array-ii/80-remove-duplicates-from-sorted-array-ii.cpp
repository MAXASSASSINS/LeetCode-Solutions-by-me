class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans = -1;
        int i = 1;
        int count = 1;
        int prevVal = nums[0];
        while (i < nums.size()){
            if(nums[i]  == prevVal){
                count++;
            }
            else{
                count = 1;
            }
            prevVal = nums[i];
            if(count > 2){
                nums[i] = INT_MAX;
            }
            i++;
        }
        for (int j = 0; j < nums.size(); ++j) {
            if(nums[j] == INT_MAX){
                int prevJIndex = j;
                while (j < nums.size() && nums[j] == INT_MAX){
                    j++;
                }
                if(j == nums.size()){
                    break;
                }
                swap(nums[j], nums[prevJIndex]);
                j = prevJIndex;
            }
        }
        for (int j = 0; j < nums.size(); ++j) {
            if(nums[j] == INT_MAX){
                return j;
            }
        }
        return nums.size();
    }
};