class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                long long int newTarget = long ((long)target - (long)nums[i] - (long)nums[j]);
                int left = j + 1;
                int right = n - 1;

                while (left < right){
                    long long int twoSum = nums[left] + nums[right];
                    if (twoSum < newTarget){
                        left++;
                    }
                    else if(twoSum > newTarget){
                        right--;
                    }
                    else{
                        vector<int> quad(4, 0);
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[left];
                        quad[3] = nums[right];
                        ans.push_back(quad);

                        while (left < right && nums[left] == quad[2])
                            left++;
                        while (left < right && nums[right] == quad[3])
                            right--;
                    }
                }
                while (j + 1 < n && nums[j] == nums[j + 1])
                    j++;
            }
            while (i + 1 < n && nums[i] == nums[i + 1])
                i++;
        }
        return ans;
    }
};