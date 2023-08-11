class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        
        while(low <= high){
            int mid = (low + high)/2;
            if(mid - 1 > 0 && nums[mid] < nums[mid - 1]){
                return nums[mid];
            }
            else if(mid + 1 < n && nums[mid] > nums[mid + 1]){
                return nums[mid + 1];
            }
            else if(nums[low] < nums[mid]){
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        
        return nums[0];
    }
};