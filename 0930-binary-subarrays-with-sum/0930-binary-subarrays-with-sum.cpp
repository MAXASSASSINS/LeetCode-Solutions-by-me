class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> m;
        
        int n = nums.size();
        int count = 0;
        int sum = 0;
        
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(sum == goal){
                count++;
            }
            if(m.find(sum - goal) != m.end()){
                count += m[sum - goal];
            }
            m[sum]++;
        }
        
        return count;
        
    }
};