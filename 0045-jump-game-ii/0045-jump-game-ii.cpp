class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int currReach = 0;
        int maxReach = 0;
        int jumps = 0;
        for(int i = 0; i < n - 1; i++){
            maxReach = max(maxReach, nums[i] + i);
            if(i == currReach){
                jumps++;
                currReach = maxReach;
            }
        }
        
        return jumps;
    }
};