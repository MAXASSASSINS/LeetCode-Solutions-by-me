class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        sort(nums.begin(), nums.end());
        auto it = unique(nums.begin(), nums.end());
        nums.resize(distance(nums.begin(), it));
        int count  = 1;
        int maxCount = 1;
        int i = 1;
        while (i < nums.size()){
            if (nums[i] - nums[i - 1] > 1){
                maxCount = max(count, maxCount);
                count = 1;
            }
            else{
                count++;
            }
            i++;
        }
        maxCount = max(count, maxCount);
        return maxCount;
    }
};