class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int n = nums.size();
        if(nums[0] > k) return k;
        
        int low = 0;
        int high = n - 1;
        
        while(low <= high){
            int mid = (low + high) / 2;
            
            int cnt = nums[mid] - (mid + 1);
            
            if(cnt < k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        
        int cnt = nums[high] - (high + 1);
        cout<<cnt<<nums[high];
        
        return nums[high] + (k - cnt);    
    }
};
