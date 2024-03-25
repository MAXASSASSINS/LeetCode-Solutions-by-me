class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]){
                swap(nums[i], nums[nums[i] - 1]);
                i--;
            }
        }
        
        for(auto x: nums){
            cout<<x<<"\t";
        }
        
        vector<int> res;
        for(int i = 0; i < n; i++){
            if(nums[i] != i + 1) 
                res.push_back(nums[i]);
        }
        
        return res;
    }
};