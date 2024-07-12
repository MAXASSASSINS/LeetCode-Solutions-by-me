class Solution {
public:
    string solve(string &s, string target){
        stack<char> st;
        for(auto c: s){
            if(st.empty()){
                st.push(c);
                continue;
            }
            string temp;
            temp += st.top();
            temp += c;
            if(temp == target){
                st.pop();
            }
            else{
                st.push(c);
            }
        }
        
        string t;
        while(!st.empty()){
            t += st.top();
            st.pop();
        }
        
        reverse(t.begin(), t.end());
        return t;

    }
    
    int maximumGain(string s, int x, int y) {
        stack<char> st;
        int ans = 0;
        string high = x > y ? "ab" : "ba";
        string low = x < y ? "ab" : "ba";
        
        // remove high priority string
        string t = solve(s, high);
        ans += (s.length() - t.length()) * (x > y ? x : y);
        
        // remove low priority string
        string u = solve(t, low);
        ans += (t.length() - u.length()) * (x < y ? x : y);
        
        
        return ans / 2;
    }
};