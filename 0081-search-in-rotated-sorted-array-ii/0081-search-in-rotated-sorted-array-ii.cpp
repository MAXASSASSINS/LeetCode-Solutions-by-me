class Solution {
public:
    bool bs(vector<int> &nums, int low, int high, int target){
        if(low < 0) return false;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(target == nums[mid]) return true;
            else if(target < nums[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        return false;
    }
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = -1;
        for(int i = 0; i < n; i++){
            if(i + 1 < n && nums[i] > nums[i + 1]){
                pivot = i + 1;
            }
        }
        
        if(pivot == -1){
            return bs(nums, 0, n - 1, target);
        }
        
        bool left = bs(nums, 0, pivot - 1, target);
        bool right = bs(nums, pivot, n - 1, target);
        
        return left || right;
    }
};