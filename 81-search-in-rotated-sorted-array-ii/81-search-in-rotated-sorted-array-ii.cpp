class Solution {
public:
    bool binarySearch(int low, int high, int target, const vector<int> &nums){
        if(low > high){
            return false;
        }
        int mid = low + (high - low) /2;
        if(nums[mid] == target){
            return true;
        }
        else if(nums[mid] < target){
            return binarySearch(mid + 1, high, target, nums);
        }
        else{
            return binarySearch(low, high - 1, target, nums);
        }
    }
    bool search(vector<int>& nums, int target) {
        int pivot = nums.size() - 1;
        for (int i = 1; i < nums.size(); ++i) {
            if(nums[i] < nums[i - 1]){
                pivot = i;
                break;
            }
        }
        bool left = binarySearch(0, pivot - 1, target, nums);
        bool right = binarySearch(pivot, nums.size() - 1, target, nums);
        return left || right;
    }
};