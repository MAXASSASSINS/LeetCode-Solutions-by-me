class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.at(i);
            if(st.empty()){
                st.push(c);
            }
            else if(st.top() == c){
                st.pop();
            }
            else{
                st.push(c);
            }
        }
        string ans;
        while (!st.empty()){
            char c = st.top();
            ans += c;
            st.pop();
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};