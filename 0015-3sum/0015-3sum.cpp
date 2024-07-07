class Solution {
public:
    int bs(vector<int> &nums, int low, int high, int target){
        while(low <= high){
            int mid = low + (high - low) / 2;
            int curr = nums[mid];
            
            if(curr == target) return mid;
            else if(curr > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        return -1;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int target = -(nums[i] + nums[j]);
                // cout<<nums[i]<<"\t"<<nums[j]<<"\t"<<target<<endl;
                int foundTargetIdx = bs(nums, j + 1, n - 1, target);
                if(foundTargetIdx != -1){
                    ans.push_back({nums[i], nums[j], nums[foundTargetIdx]});
                }
                while(j + 1 < n && nums[j] == nums[j + 1]){
                    j++;
                }
                // cout<<j<<endl;
            }
            while(i + 1 < n && nums[i] == nums[i + 1]){
                i++;
            }
        }
        return ans;
    }
};