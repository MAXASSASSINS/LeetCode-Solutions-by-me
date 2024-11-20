class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i = 1, j = 0;
        int n = nums.size();
        while(i < n && j < n){
            if(i % 2 == 1 && nums[i] % 2 == 1){
                i+=2;
            }
            else if(j % 2 == 0 && nums[j] % 2 == 0){
                j+=2;
            }
            else{
                swap(nums[i], nums[j]);
                i+=2;
                j+=2;
            }
        }
        
        return nums;
    }
};