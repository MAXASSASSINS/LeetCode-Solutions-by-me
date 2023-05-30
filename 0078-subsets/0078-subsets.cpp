class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i <= (1 << n) - 1; i++){
            vector<int> temp;
            int num = i;
            for(int j = 0; j <= n - 1; j++){
                if(num & 1){
                    temp.push_back(nums[j]);
                }
                num = num >> 1;
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};