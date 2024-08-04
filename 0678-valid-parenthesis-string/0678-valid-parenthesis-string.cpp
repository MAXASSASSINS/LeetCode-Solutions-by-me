class Solution {
public:
    bool solve(string &s, int index, int cnt, vector<vector<int>> &dp){
        if(cnt < 0) return false;
        
        if(index >= s.length()){
            return cnt == 0;
        }
        
        if(dp[index][cnt] != -1) return dp[index][cnt];
        
        bool open, close, empty;
        if(s[index] == '('){
            return dp[index][cnt] = solve(s, index + 1, cnt + 1, dp);
        }
        else if(s[index] == ')'){
            return dp[index][cnt] = solve(s, index + 1, cnt - 1, dp);
        }
        return dp[index][cnt] = 
            solve(s, index + 1, cnt + 1, dp) ||
            solve(s, index + 1, cnt - 1, dp) ||
            solve(s, index + 1, cnt, dp);
    }
    
    bool checkValidString(string s) {
        vector<vector<int>> dp(101, vector<int>(101, -1));
        return solve(s, 0, 0, dp);
    }
};