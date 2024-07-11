class Solution {
public:
//     void solve(string &s, int prev, int &index){
//         if(index >= s.length()) return;
        
//         if(s[index] == '('){
//             prev = index;
//             index++;
//             solve(s, prev, index);
//         }
//         else if(s[index] == ')'){
//             reverse(s.begin() + prev + 1, s.begin() + index);
//             cout<<s<<endl;
//             return;
//         }
//         else{
//             index++;
//             solve(s, prev, index);
//         }
//     }
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int> st;
        
        vector<pair<int,int>> vec;
        
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                int open = st.top();
                st.pop();
                vec.push_back({open, i});
            }
        }
        
        for(auto p: vec){
            int start = p.first + 1;
            int end = p.second;
            reverse(s.begin() + start, s.begin() + end);
        }
        
        string t;
        for(auto c: s){
            if(c == '(' || c == ')') continue;
            t += c;
        }
        
        return t;
        
    }
};