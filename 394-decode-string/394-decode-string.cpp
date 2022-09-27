class Solution {
public:
    string decodeString(string s) {
        string ans;
        stack<char> st;
        int i = 0;
        string temp;
        while (i < s.length()){
            temp = "";
            while (i < s.length() && s.at(i) != ']'){
                st.push(s.at(i));
                i++;
            }
            if (i >= s.length() && s.at(s.length() - 1) != ']'){
                break;
            }
            i++;

            while (!st.empty() && st.top() != '['){
                temp += st.top();
                st.pop();
            }
            std::reverse(temp.begin(), temp.end());
            st.pop();
            string multiplier;
            while (!st.empty() && st.top() >= '0' && st.top() <= '9'){
                multiplier += st.top();
                st.pop();
            }
            std::reverse(multiplier.begin(), multiplier.end());
            string temp2 = temp;
            for (int j = 1; j < stoi(multiplier); ++j) {
                temp += temp2;
            }
            for (int j = 0; j < temp.length(); ++j) {
                st.push(temp[j]);
            }
        }

        while (!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};