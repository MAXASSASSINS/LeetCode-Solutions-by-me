class Solution {
public:
    int solve(string &s, int index, vector<int> &dp){
        if(index >= s.length()){
            return 1;
        }
        
        if(dp[index] != -1) return dp[index];
        
        int inclOne = 0, inclTwo = 0;
        
        if(s[index] != '0'){
            inclOne += solve(s, index + 1, dp);
        }
        
        if(index + 1 < s.length()){
            string temp = s.substr(index, 2);
            if(temp >= "1" && temp <= "26"){
                inclTwo += solve(s, index + 2, dp);
            }
        }
        
        return dp[index] = inclOne + inclTwo;
        
    }
    int numDecodings(string s) {
        vector<int> dp(s.length(), -1);
        return solve(s, 0, dp);
    }
};