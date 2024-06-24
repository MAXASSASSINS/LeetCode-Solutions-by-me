class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                for(int j = 0; j < 3; j++){
                    if(i + j == n) return -1;
                    nums[i + j] = 1 - nums[i + j];
                }
                cnt++;
            }
        }
        return cnt;
    }
};