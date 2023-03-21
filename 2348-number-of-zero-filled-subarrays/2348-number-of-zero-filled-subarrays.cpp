class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        long long ans = 0;
        int count = 0;
        while(i < n){
            if(nums[i] == 0){
                count++;
            }
            else{
                ans += (long long)count * (count + 1)/2;
                count = 0;
            }
            i++;
        }
        
        
        ans += (long long)count * (count + 1) /2;
        
        return ans;
    }
};