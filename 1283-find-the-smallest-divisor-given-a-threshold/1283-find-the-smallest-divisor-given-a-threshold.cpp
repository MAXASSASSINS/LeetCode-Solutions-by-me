class Solution {
public:
    int sum(vector<int> &nums, int n){
        int ans = 0;
        for(auto x: nums){
            ans += ceil(double(x)/n);
        }
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = nums[0];
        for(auto n: nums){
            maxi = max(maxi, n);
        }
        int l = 1;
        int h = maxi;
        int ans = -1;
        while(l <= h){
            int mid = l + (h - l)/2;
            int x = sum(nums, mid);
            if(x > threshold){
                l = mid + 1;
            }
            else if(x <= threshold){
                h = mid - 1;
                ans = mid;
            }
        }
        
        
        return ans;
        
        
        
    }
};