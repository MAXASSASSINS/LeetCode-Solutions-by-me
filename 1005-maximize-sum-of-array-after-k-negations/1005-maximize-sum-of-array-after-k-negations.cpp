class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0;
        while (k > 0){
            while (i < nums.size() && k > 0 && nums[i] < 0){
                nums[i] *= -1;
                i++;
                k--;
            }
            if(k == 0)
                break;
            sort(nums.begin(), nums.end());
            if(nums[0] >= 0){
                while (k > 0){
                    nums[0] *= -1;
                    k--;
                }

            }
        }
        int sum = 0;
        for (int j = 0; j < nums.size(); ++j) {
            sum += nums[j];
        }
        return sum;
    }
};