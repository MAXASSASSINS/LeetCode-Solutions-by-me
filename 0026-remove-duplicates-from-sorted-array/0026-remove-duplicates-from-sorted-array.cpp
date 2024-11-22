class Solution {
public:
    //        i      
    // [1, 2, 3, 3, 3, 4, 5, 5, 6, 9]
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 1;
        
        while(i < n){
            if(nums[i] <= nums[i - 1]){
                int j = i + 1;
                while(j < n && nums[j] <= nums[i - 1]){
                    j++;
                }
                if(j < n){
                    swap(nums[i], nums[j]);
                }
            }
            i++;
        }
        
        for(int k = 1; k < n; k++){
            if(nums[k] <= nums[k - 1]) return k;
        }
        
        return n;
        
    }
};