class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int low = 0;
        int high = nums.size() - 1;
        int maxi = INT_MIN;
        
        while(low < high){
            int sum = nums[low] + nums[high];
            maxi = max(maxi, sum);
            low++;
            high--;
        }
        
        return maxi;
        
    }
};