class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int cons = 1;
        int n = nums.size();
        if(n == 1) return nums;
        vector<int> res(n - k + 1, -1);
        int maxi = nums[0];
        int j = 1;
        
        for(int i = 1; i < k; i++){
            if(nums[i] == nums[i - 1] + 1){
                cons++;
            }
            else{
                cons = 1;
            }
        }
        
        if(cons == k){
            res[0] = nums[k - 1]; 
        }
        
        for(int i = k; i < nums.size(); i++){
            if(nums[i] == nums[i - 1] + 1){
                cons++;
            }
            else{
                cons = 1;
            }
            maxi = nums[i];
            if(cons >= k){
                res[j] = maxi;
            }
            j++;
        }
        
        return res;
    }
};