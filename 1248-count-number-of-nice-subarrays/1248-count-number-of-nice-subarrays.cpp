class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            nums[i] %= 2;
        }
        
        unordered_map<int,int> m;
        int sum = 0;
        int ans = 0;
        
        m[sum] = 1;
        
        for(int i = 0; i < n; i++){
            sum += nums[i];
            
            if(m.find(sum - k) != m.end()){
                ans += m[sum - k];
            }
            m[sum]++;
        }
        
        return ans;
    }
};