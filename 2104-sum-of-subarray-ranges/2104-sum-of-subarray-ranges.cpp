class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        
        stack<int> st;
        
        long long ans = 0;

        for(int i = 0; i <= nums.size(); i++){
            while(!st.empty() && (i == n || nums[st.top()] >= nums[i])){
                int ele = st.top();
                st.pop();
                
                int rightBound = i;
                int leftBound = st.empty() ? -1 : st.top();
                
                ans -= (long long)nums[ele] * (rightBound - ele) * (ele - leftBound);
            }
            st.push(i);
        }
        
        st.pop();
        
        for(int i = 0; i <= nums.size(); i++){
            while(!st.empty() && (i == n || nums[st.top()] <= nums[i])){
                int ele = st.top();
                st.pop();
                
                int rightBound = i;
                int leftBound = st.empty() ? -1: st.top();
                
                ans += (long long)nums[ele] * (rightBound - ele) * (ele - leftBound);
            }
            st.push(i);
        }
    
        return ans;
    }
};