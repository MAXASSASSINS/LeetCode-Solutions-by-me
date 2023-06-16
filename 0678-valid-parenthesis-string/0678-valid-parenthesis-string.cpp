class Solution {
public:
    bool solve(string s, int op, int index){
        if(index == s.length()) return op == 0;
        
        bool ans = false;
        
        char c = s[index];
        
        if(c == '('){
            ans = ans || solve(s, op + 1, index + 1);
        }
        else if(c == ')'){
            if(op)
                ans = ans || solve(s, op - 1, index + 1);
        }
        else{
            ans = ans || solve(s, op + 1, index + 1);
            if(op){
                ans = ans || solve(s, op - 1, index + 1);                
            }
            ans = ans || solve(s, op, index + 1);
        }
        
        return ans;
        
    }
    
    bool solveMem(string s, int op, int index, vector<vector<int>> &dp){
        if(index == s.length()) return op == 0;
        
        if(dp[index][op] != -1) return dp[index][op]; 
        
        bool ans = false;
        
        char c = s[index];
        
        if(c == '('){
            ans = ans || solveMem(s, op + 1, index + 1, dp);
        }
        else if(c == ')'){
            if(op)
                ans = ans || solveMem(s, op - 1, index + 1, dp);
        }
        else{
            ans = ans || solveMem(s, op + 1, index + 1, dp);
            if(op){
                ans = ans || solveMem(s, op - 1, index + 1, dp);                
            }
            ans = ans || solveMem(s, op, index + 1, dp);
        }
        
        return dp[index][op] = ans;
        
    }
    
    bool checkValidString(string s) {
        stack<char> st;
        // return solve(s, 0, 0);
        
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
        return solveMem(s, 0, 0, dp);
        
    }
};