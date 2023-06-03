class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        
        int n = nums.size();
        vector<int> ans(n);
        
        for(int i = 2*n - 1; i >= 0; i--){
            int num = nums[i % n];
            while(!st.empty() && st.top() <= num){
                st.pop();
            }
            
            ans[i % n] = st.empty() ? -1 : st.top();
            st.push(num);
        }
        
        // ans.resize(n);
        
        return ans;
        
        
    }
};