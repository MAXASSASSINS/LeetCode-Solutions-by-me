class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n),  suffix(n);
        stack<pair<int,int>> st;
        
        for(int i = 0; i < n; i++){
            int x = nums[i];
            while(!st.empty() && x < st.top().first){
                suffix[st.top().second] = i - 1;
                st.pop();
            }
            st.push({x, i});
        }
        
        while(!st.empty()){
            suffix[st.top().second] = n - 1;
            st.pop();
        }
        
        for(int i = n - 1; i >= 0; i--){
            int x = nums[i];
            while(!st.empty() && x < st.top().first){
                prefix[st.top().second] = i + 1;
                st.pop();
            }
            st.push({x, i});
        }
        
        while(!st.empty()){
            prefix[st.top().second] = 0;
            st.pop();
        }
        
        for(auto x: suffix){
            cout<<x<<"\t";
        }
        cout<<endl;
        for(auto x: prefix){
            cout<<x<<"\t";
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(prefix[i] <= k && suffix[i] >= k){
                int len = suffix[i] - prefix[i] + 1;
                ans = max(ans, nums[i] * len);
            }
        }
        
        return ans;
    }
};