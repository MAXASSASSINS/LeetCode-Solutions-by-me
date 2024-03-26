class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ans = 0;
        int i = 0;
        int n = nums.size();
        while(i < n) {
            if(nums[i] != i + 1){
                if(nums[i] >= n || nums[i] <= 0){
                    i++;
                }
                else{
                    if(nums[nums[i] - 1] == nums[i]){
                        i++;
                    }
                    else{
                        swap(nums[i], nums[nums[i] - 1]);
                    }
                }
            }
            else{
                i++;
            }
        }
        i  = 0;
        while (i < n){
            if (nums[i] != i + 1)
                return i + 1;
            i++;
        }
        return n + 1;
    }
};