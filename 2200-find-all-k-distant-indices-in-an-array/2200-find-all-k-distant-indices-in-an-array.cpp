class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> res;
        for(int i = 0; i < n; i++){
            if(nums[i] == key){
                for(int j = max(0, i - k);  j < min(n, i + k + 1); j++){
                    if(res.size() != 0 && j <= res.back()){
                        continue;
                    }
                    res.push_back(j);
                }
            }
        }
        
        return res;
        
    }
};