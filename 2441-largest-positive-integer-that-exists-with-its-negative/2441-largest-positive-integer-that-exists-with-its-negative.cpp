class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int i = 0; 
        int j = nums.size() - 1;
        while(i < j){
            bool bipolar = (nums[i] < 0 && nums[j] > 0) || (nums[i] > 0 && nums[j] < 0);
            int x = abs(nums[i]);
            int y = abs(nums[j]);
            
            if(x > y){
                i++;
            }
            else if(x < y){
                j--;
            }
            else{
                if(bipolar)
                    return x;
                i++;
            }
        }
        
        
        return -1;
    }
};