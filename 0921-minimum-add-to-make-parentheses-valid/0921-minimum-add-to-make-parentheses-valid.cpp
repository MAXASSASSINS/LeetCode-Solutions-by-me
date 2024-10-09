class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int n = s.length();
        
        int count = 0;
        for(int i = 0; i < n; i++){
            char c = s[i];
            if(c == '('){
                st.push(c);
            }
            else{
                if(st.empty()){
                    count++;
                }
                else{
                    st.pop();
                }
            }
        }
        
        while(!st.empty()){
            st.pop();
            count++;
        }
        
        return count;
    }
};