class Solution {
public:
    int findPivot(vector<int> nums, int low, int high) {
        if(high < low){
            return -1;
        }
        int mid = (low + high) / 2;
        if (mid + 1 < nums.size() && nums[mid] > nums[mid + 1]) {
            return mid;
        } else if (mid - 1 > 0 && nums[mid] < nums[mid - 1]) {
            return mid - 1;
        } else if(nums[low] > nums[mid]){
            return findPivot(nums, low, mid - 1);
        }
        else if(nums[mid] > nums[high]){
            return findPivot(nums, mid + 1, high);
        }
        return -1;
    }

    int binarySearch(vector<int> nums, int target, int low, int high){
        if(high < low){
            return -1;
        }
        int mid = (low + high) /2;
        if (nums[mid] < target){
            return binarySearch(nums, target, mid + 1, high);
        }
        else if(nums[mid] > target){
            return binarySearch(nums, target, low, mid -1);
        }
        else
            return mid;

    }

    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int tempResult = findPivot(nums, low, high);
        int ans = 0;
        if(tempResult == -1){
            ans = binarySearch(nums,target, low, high);
            return ans;
        }
        ans = binarySearch(nums, target, low, tempResult);
        if(ans != -1){
            return ans;
        }
        else{
            if(tempResult + 1 < nums.size())
            ans = binarySearch(nums, target, tempResult + 1, high);
            return ans;
        }

        return ans;
    }
};