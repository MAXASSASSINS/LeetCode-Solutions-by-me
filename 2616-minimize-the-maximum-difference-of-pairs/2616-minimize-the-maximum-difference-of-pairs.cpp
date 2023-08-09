class Solution {
public:
    bool isPossible(vector<int> &nums, int p, int diff){
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] - nums[i - 1] <= diff){
                p--;
                i++;
            }
        }
        
        return p <= 0;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxDiff = nums[n - 1] - nums[0];
        
        int low = 0;
        int high = maxDiff;
        
        int ans = high;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(nums, p, mid)){
                high = mid - 1;
                ans = mid;
            }
            else{
                low = mid + 1;
            }
        }
        
        return ans;
        
    }
};