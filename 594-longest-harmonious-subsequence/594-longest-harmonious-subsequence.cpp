class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size() <= 1){
            return 0;
        }
        int longest = 0;
        int st = 0;
        int en = 1;
        while (st <= en && en < nums.size()){
            if(nums[en] - nums[st] == 1){
                longest = max(longest, en - st + 1);
                en++;
            }
            else if(nums[en] - nums[st] > 1){
                st++;
            }
            else{
                en++;
            }

        }
        return longest;
    }
};