class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<long long> prefix(nums.size() + 1);
        
        for(int i = 0; i < nums.size(); i++){
            prefix[i + 1] += (long long)prefix[i] + nums[i];
        }
        
        
        vector<int> avgs(nums.size());
        for(int i = 0; i < nums.size(); i++){
            if(i - k < 0 || (i + k) >= nums.size()){
                avgs[i] = -1;
                continue;
            }
            long long left = prefix[i - k];
            long long right = prefix[i + k + 1];
            // cout<<right<<" ";
            avgs[i] = (int)((right - left)/(2*k + 1));
            // cout<<avgs[i]<<"\t";
        }
        
        return avgs;
    }
};