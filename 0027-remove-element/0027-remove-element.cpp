class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int count = 0;
        while(i < n){
            if(nums[i] == val){
                j = i + 1;
                while(j < n && nums[j] == val){
                    j++;
                }
                if(j < n)
                    swap(nums[i], nums[j]);
            }
            i++;
        }
        
        for(auto x: nums){
            if(x == val) count++;
        }
        
        return n - count;
    }
};