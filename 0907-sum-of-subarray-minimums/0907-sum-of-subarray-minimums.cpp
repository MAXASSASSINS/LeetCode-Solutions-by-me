class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n);
        vector<int> right(n);
        
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                left[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        
        while(!st.empty()){
            left[st.top()] = n - st.top();
            st.pop();
        }
        
        
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] > arr[i]){
                right[st.top()] = st.top() - i;
                st.pop();
            }
            st.push(i);
        }
        
        
        
        while(!st.empty()){
            right[st.top()] = st.top() + 1;
            st.pop();
        }
        
        int mod = 1e9 + 7;
        
        long long ans = 0;
        for(int i = 0; i < n; i++){
            ans += (long long)arr[i] * left[i] * right[i];
            ans = ans % mod;
        }
        
        
        return (int)ans;
    }
};