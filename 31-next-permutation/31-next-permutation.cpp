class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        // Find the item that is violating the order from right(ascending order from right to left)
        
        int vr = -1;
        
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                vr = i;
                break;
            }
        }
        
        // Return if there is not violating element there will be no next permutation
        if(vr == -1){
           reverse(nums, 0); // as question says
        }else{
            // Find the next grater then nums[vr] and swap them
            
            int gvr = n-1;
            for(int i = n-1; i > vr; i--){
                if(nums[i] > nums[vr]){
                    gvr = i;
                    break;
                }
            }
            
            swap(nums[vr], nums[gvr]);
            
            // reverse the right array from vr
            reverse(nums, vr+1);
        }
            
    }
    
    
    void reverse(vector<int> &arr, int idx){
        int i = idx;
        int j = arr.size()-1;
        
        while(i < j){
            swap(arr[i], arr[j]);
            i++;j--;
        }
    }
};