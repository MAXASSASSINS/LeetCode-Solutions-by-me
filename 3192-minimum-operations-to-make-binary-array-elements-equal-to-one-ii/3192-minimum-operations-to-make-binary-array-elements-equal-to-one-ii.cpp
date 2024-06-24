class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0 && cnt % 2 == 0){
                cnt += 1;
            }
            else if(nums[i] == 1 && cnt % 2 == 1){
                cnt += 1;
            }
        }
        
        return cnt;
    }
};