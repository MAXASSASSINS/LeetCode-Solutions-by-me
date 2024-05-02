class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int i = 0; 
        int j = nums.size() - 1;
        while(i < j){
            int x = nums[i];
            int y = nums[j];
            
            if(x + y < 0){
                i++;
            }
            else if(x + y > 0){
                j--;
            }
            else{
                return abs(x);
            }
        }

        return -1;
    }
};