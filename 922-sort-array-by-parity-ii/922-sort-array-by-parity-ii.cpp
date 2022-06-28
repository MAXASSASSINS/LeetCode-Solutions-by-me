class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        int j = 0;
        while(i < nums.size() && j < nums.size()){
            if(i % 2 == 1){
                i++;
            }
            else if(j % 2 == 0){
                j++;
            }
            else if(i % 2 == 0 && nums[i] % 2 == 0){
                i++;
            }
            else if(j % 2 == 1 && nums[j] % 2 == 1){
                j++;
            }
            else if(i % 2 == 0 && nums[i] % 2 == 1 && j % 2 == 1 &&  nums[j] % 2 == 0){
                swap(nums[i], nums[j]);
            }
        }

        return nums;
    }
};