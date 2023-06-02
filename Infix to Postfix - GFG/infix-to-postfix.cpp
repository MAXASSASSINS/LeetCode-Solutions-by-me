//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        // Your code here
        int i = 0;
        int len = s.length();
        
        unordered_map<char, int> m;
        m.insert({'-', 0});
        m.insert({'+', 0});
        m.insert({'*', 1});
        m.insert({'/', 1});
        m.insert({'^', 2});
        
        
        stack<int> st;
        string ans;
        
        
        while(i < len){
            char c = s[i];
            if(c == '(') {
                st.push(c);
            }
            else if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){
                if(st.empty() || st.top() == '(') {
                    st.push(c);
                }
                // else if(c == '^' && st.top() == '^'){
                //     st.push(c);
                // }
                else{
                    while(!st.empty() && st.top() != '(' && m[st.top()] >= m[c]){
                        ans += st.top();
                        st.pop();
                    }
                    st.push(c);
                }
            }
            else if(c == ')'){
                while(st.top() != '('){
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                ans += c;
            }
            i++;
        }
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};




//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends