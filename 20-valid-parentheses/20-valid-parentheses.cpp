class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); ++i) {
            if(s.at(i) == '(' || s.at(i) == '{' || s.at(i) == '['){
                st.push(s.at(i));
            }
            else if(st.empty()){
                return  false;
            }
            else{
                if((s.at(i) == ')'  && st.top() != '(') ||
                    (s.at(i) == '}'  && st.top() != '{') ||
                    (s.at(i) == ']'  && st.top() != '['))
                    return false;
                else
                    st.pop();
            }
        }
        if(st.empty()) {
            return true;
        }
        else
            return false;
    }
};