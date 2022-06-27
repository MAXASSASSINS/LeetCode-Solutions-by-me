class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size() == 1){
            return true;
        }
        int n = nums.size();
        int arr[2];
        arr[0] = 0;
        arr[1] = 0;

        for (int i = 1; i < n; ++i) {
            if(nums[i - 1] < nums[i]){
                arr[0] = 1;
            }
            else if(nums[i - 1] == nums[i]){
                continue;
            }
            else{
                arr[1] = 1;
            }
        }
        return (arr[0] != arr[1]) || (arr[0] == 0 && arr[1] == 0);
    }
};