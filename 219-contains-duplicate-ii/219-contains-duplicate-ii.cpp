class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        bool ans = false;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if(m.count(nums[i]) == 0){
                m.insert(pair<int,int>(nums[i], i));
            }
            else{
                if(abs(m[nums[i]] - i) <= k){
                    return true;
                }
                else{
                    m[nums[i]] = i;
                }
            }
        }
        return ans;
    }
};