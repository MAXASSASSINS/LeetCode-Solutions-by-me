class Solution {
public:
    void binarySearch(vector<int> &nums, int low, int high, int target, int *st, int *en) {
        if(low > high)
            return;

        int mid = (low + high) / 2;
        if (nums[mid] < target) {
            low = mid + 1;
            binarySearch(nums, low, high, target, st, en);
        } else if (nums[mid] > target) {
            high = mid - 1;
            binarySearch(nums, low, high, target, st, en);
        } else {
            if (*st == -1) {
                *st = *en = mid;
            } else if (mid <= *st) {
                *st = mid;
            } else if (mid >= *en) {
                *en = mid;
            }
            binarySearch(nums, mid + 1, high, target, st, en);
            binarySearch(nums, low, mid - 1, target, st, en);
            return;
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int st = -1;
        int en = -1;
        vector<int> ans;
        int low = 0;
        int high = nums.size() - 1;
        binarySearch(nums, low, high, target, &st, &en);
        ans.push_back(st);
        ans.push_back(en);
        return ans;
    }
};