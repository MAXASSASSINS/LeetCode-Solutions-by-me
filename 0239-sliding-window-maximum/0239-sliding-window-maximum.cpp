class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        
        set<pair<int,int>, greater<pair<int,int>>> st;
        
        for(int i = 0; i < k; i++){
            st.insert({nums[i], i});
        }
        
        ans.push_back(st.begin()->first);
        
        for(int i = k; i < n; i++){
            st.erase({nums[i - k], i - k});
            st.insert({nums[i], i});
            ans.push_back(st.begin()->first);
        }
        
        return ans;
    }
};