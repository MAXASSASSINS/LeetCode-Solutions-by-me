class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        int length = 0;
        if(s.length() == 0){
            return ans;
        }
        stack<int> st;
        st.push(-1);
        for (int i = 0; i < s.length(); ++i) {
            if(s.at(i) == '(')
                st.push(i);
            else {
                st.pop();
                if(st.empty())
                    st.push(i);
                else{
                    ans = max(ans, i - st.top());
                }
            }
        }
        return ans;
    }
};