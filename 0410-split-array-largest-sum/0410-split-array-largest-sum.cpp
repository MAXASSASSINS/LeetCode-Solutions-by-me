class Solution {
public:
    bool possible(vector<int>& nums, int k, int mid){
        int cnt = 1;
        int temp = 0;
        for(auto n: nums){
            if(n > mid) return false;
            if(temp + n > mid){
                temp = n;
                cnt++;
            }
            else{
                temp += n;
            }
        }
        
        return cnt <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int mini = INT_MAX;
        int total = 0;
        for(auto n: nums){
            mini = min(mini, n);
            total += n;
        }
        
        int l = mini;
        int h = total;
        
        while(l <= h){
            int mid = l + (h - l)/2;
            
            if(possible(nums, k, mid)){
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        
        return l;
        
    }
};