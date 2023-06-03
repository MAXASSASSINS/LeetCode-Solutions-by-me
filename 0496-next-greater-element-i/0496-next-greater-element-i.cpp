class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans;
        
        
        vector<int> temp(10001);
        
        stack<int> st;
        
        for(int i = n2 - 1; i >= 0; i--){
            int num = nums2[i];
            while(!st.empty() && st.top() <= num){
                st.pop();
            }
            temp[num] = st.empty() ? -1 : st.top();
            st.push(num);
        }
        
        
        for(auto num: nums1){
            ans.push_back(temp[num]);
        }
        
        
        
        return ans;
    }
};