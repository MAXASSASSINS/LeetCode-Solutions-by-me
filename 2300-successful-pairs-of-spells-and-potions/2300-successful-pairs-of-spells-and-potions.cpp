class Solution {
public:
    int find(long long target, vector<int> &nums){
        int l = 0;
        int h = nums.size() - 1;
        while(l <= h){
            int mid = l + (h - l)/2;
            if(nums[mid] < target){
                l = mid + 1;
            }
            else{
                h = mid - 1;
            }
        }
        
        return l;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        for(auto n: spells){
            long long idx = success % n;
            if(idx == 0){
                idx = find(success/n, potions);
            }
            else{
                idx = find((success/n) + 1, potions);
            }
            int count = potions.size() - idx;
            if(count < 0) count = 0;
            ans.push_back(count);
        }
        
        return ans;
    }
};