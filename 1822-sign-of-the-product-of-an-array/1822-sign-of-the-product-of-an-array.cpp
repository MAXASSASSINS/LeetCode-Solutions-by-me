class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negatives = 0;
        for(auto n: nums){
            if(n == 0) return 0;
            if(n < 0) negatives++;
        }
        
        if(negatives % 2 == 1) return -1;
        return 1;
        
    }
};