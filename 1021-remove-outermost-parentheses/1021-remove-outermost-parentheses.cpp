class Solution {
public:
    string removeOuterParentheses(string s) {
        int open = 0;
        int close = 0;
        string ans;
        for(auto c: s){
            if(c == '(') {
                open++;
                if(open > 1) ans += '(';
            }
            else{
                close++;
                if(close < open) ans += ')';
            }
            if(open == close){
                close = 0;
                open = 0;
            }
        }

        return ans;
    }
};