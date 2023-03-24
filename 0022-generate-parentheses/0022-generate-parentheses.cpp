class Solution {
public:

    void helper(int n,int openCount, int closeCount,  vector<string> &ans, string temp) {
        if(temp.length() == 2 * n){
            ans.push_back(temp);
            return;
        }
        if(openCount < n){
            helper(n, openCount + 1, closeCount, ans, temp + '(');
        }
        if(closeCount < openCount){
            helper(n, openCount, closeCount + 1, ans, temp + ')');
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(n, 0, 0, ans, "");
        return ans;
    }
};