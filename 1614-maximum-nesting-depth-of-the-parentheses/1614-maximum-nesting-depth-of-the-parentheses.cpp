class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        stack<char> st;
        for(auto c: s){
            if(c == '('){
                st.push('(');
                ans = max(ans, (int)st.size());
            }
            else if(c == ')'){
                st.pop();
            }
            else{
                continue;
            }
        }
        
        return ans;
    }
};