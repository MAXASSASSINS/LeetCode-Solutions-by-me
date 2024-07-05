class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;
        for(int i = n - 1; i > 0; i--){
            if(nums[i - 1] < nums[i]){
                pivot = i;
                break;
            }
        }
        if(pivot == -1){
            sort(nums.begin(), nums.end());
            return;            
        } 
        
        int replacedElemIndex = -1;
        for(int i = pivot; i < n; i++){
            if(replacedElemIndex == -1 || nums[replacedElemIndex] > nums[i] && nums[i] > nums[pivot - 1]){
                replacedElemIndex = i;
            }
        }     
        swap(nums[replacedElemIndex], nums[pivot - 1]);
        sort(nums.begin() + pivot, nums.end());
    }
};