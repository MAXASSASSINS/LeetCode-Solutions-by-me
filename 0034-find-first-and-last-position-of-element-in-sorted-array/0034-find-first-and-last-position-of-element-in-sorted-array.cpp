class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size() - 1;
        vector<int> ans = {-1, -1};
        while(l <= h){
            int mid = l + (h - l)/2;
            if(nums[mid] < target){
                l = mid + 1;
            }
            else if(nums[mid] > target){
                h = mid - 1;
            }
            else{
                h = mid - 1;
                ans[0] = mid;
            }
        }
        
        l = 0;
        h = nums.size() - 1;
        while(l <= h){
            int mid = l + (h - l)/2;
            if(nums[mid] < target){
                l = mid + 1;
            }
            else if(nums[mid] > target){
                h = mid - 1;
            }
            else{
                l = mid + 1;
                ans[1] = mid;
            }
        }
        
        return ans;
    }
};