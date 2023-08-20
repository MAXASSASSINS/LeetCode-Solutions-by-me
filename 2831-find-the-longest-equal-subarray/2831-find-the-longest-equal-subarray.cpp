class Solution {
public:
    
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int n = nums.size();
        int i = 0;
        int maxf = 0;
        
        for(int j = 0; j < n; j++){
            m[nums[j]]++;
            if(m[nums[j]] > maxf){
                maxf = m[nums[j]];
            }
            int op = j - i + 1 - maxf;
            if(op > k){
                m[nums[i]]--;
                i++;
            }
        }
        
        return maxf;
    }
};