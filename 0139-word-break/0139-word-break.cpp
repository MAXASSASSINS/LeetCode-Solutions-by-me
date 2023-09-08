class Solution {
public:
    bool solve(string s, int index, unordered_set<string> &m){
        if(index == s.size()) return true;
        
        for(int i = index; i < s.size(); i++){
            if(m.find(s.substr(index, i - index + 1)) != m.end() && solve(s, i + 1, m)){
                return true;
            }
        }
        return false;
    }
    bool solveMem(string s, int index, unordered_set<string> &m, vector<int> &dp){
        if(index == s.size()) return true;
        
        if(dp[index] != -1) return dp[index];
        
        for(int i = index; i < s.size(); i++){
            if(m.find(s.substr(index, i - index + 1)) != m.end() && solveMem(s, i + 1, m, dp)){
                return dp[index] = true;
            }
        }
        return dp[index] =  false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size() + 1, -1);
        unordered_set<string> m(wordDict.begin(), wordDict.end());
        // return solve(s, 0, m);
        return solveMem(s, 0, m, dp);
    }
};