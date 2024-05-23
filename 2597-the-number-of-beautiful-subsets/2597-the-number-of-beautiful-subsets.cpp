class Solution {
public:
    
    int solve(vector<int> &nums, const int k, int index, vector<int> &temp){
        if(index == nums.size()) return 1;
        
        int excl =  solve(nums, k, index + 1, temp);
        int incl = 0;
        if(temp.size() == 0){
            temp.push_back(nums[index]);
            incl = solve(nums, k, index + 1, temp);
            temp.pop_back();
            
        }
        else{
            bool found = false;
            for(auto x: temp){
                if(abs(x - nums[index]) == k){
                    found = true;
                    break;
                }
            }
            if(!found){
                temp.push_back(nums[index]);
                incl =  solve(nums, k, index + 1, temp);
                temp.pop_back();
            }
        }
        
        return incl + excl;    
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> temp;
        return solve(nums, k, 0, temp) - 1;
    }
};