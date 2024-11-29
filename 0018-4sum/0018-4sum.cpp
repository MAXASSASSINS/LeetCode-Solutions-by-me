class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                long long reqSum = 1LL * target - (nums[i] + nums[j]);
                
                int k = j + 1;
                int l = n - 1;
                while(k < l){
                    long long sum = nums[k] + nums[l];
                    
                    if(sum > reqSum){
                        l--;
                    }
                    else if(sum < reqSum){
                        k++;
                    }
                    else{
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        res.insert(temp);
                        l--;
                        k++;
                    }
                }
            }
        }
        
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};