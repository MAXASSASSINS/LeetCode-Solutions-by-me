class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int times = 0;
        int ans = 0;
        vector<int> flipped(n, 0);
        
        for(int i = 0; i < nums.size(); i++){
            if(i - k >= 0){
                times -= flipped[i - k];
            }    
            if(nums[i] == 0 && times % 2 == 0){
                if(i + k > n) return -1;
                times ++;
                ans++;
                flipped[i] = 1;
            }
            else if(nums[i] == 1 && times % 2 == 1){
                if(i + k > n) return -1;
                times ++;
                ans++;
                flipped[i] = 1;   
            }
        }
        
        
        
        return ans;
    }
};