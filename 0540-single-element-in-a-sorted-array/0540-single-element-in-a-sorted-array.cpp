class Solution {
public:
    int binary(vector<int> &nums, int st, int en, int n){
        int mid = st + (en - st)/2;
        if(mid % 2 == 1 && mid + 1 < n  && nums[mid] == nums[mid + 1]){
            return binary(nums, st, mid - 1, n);
        }
        if(mid % 2 == 1 && mid - 1 >= 0 && nums[mid] == nums[mid - 1]){
            return binary(nums, mid + 1, en, n);
        }
        if(mid % 2 == 0 && mid + 1 < n && nums[mid] == nums[mid + 1]){
            return binary(nums, mid + 1, en, n);
        }
        if(mid % 2 == 0 && mid - 1 >= 0 && nums[mid] == nums[mid - 1]){
            return binary(nums, st, mid - 1, n);
        }

        return nums[mid];
    }
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        return binary(nums, 0, n, n);
    }
};