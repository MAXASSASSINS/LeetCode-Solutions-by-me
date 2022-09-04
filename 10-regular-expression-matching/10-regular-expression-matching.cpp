class Solution {
public:
    bool solve(string &s, string &p, int i, int j){
        if(i >= s.length() && j >= p.length()){
            return true;
        }
        if(j >= p.length() && i < s.length()){
            return false;
        }

        bool match = i < s.length() && (s[i] == p[j] || p[j] == '.');


        if(j + 1 < p.length() && p[j + 1] == '*'){
            return (match && solve(s, p, i + 1, j)) || solve(s, p, i, j + 2);
        }
        else if(match){
            return solve(s, p , i + 1, j + 1);
        }
        else{
            return false;
        }
    }

    bool solveMem(string &s, string &p, int i, int j, vector<vector<int>> &dp){
        if(i >= s.length() && j >= p.length()){
            return true;
        }
        if(j >= p.length() && i < s.length()){
            return false;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        bool match = i < s.length() && (s[i] == p[j] || p[j] == '.');

        if(j + 1 < p.length() && p[j + 1] == '*'){
            return dp[i][j] = (match && solveMem(s, p, i + 1, j, dp)) || solveMem(s, p, i, j + 2, dp);
        }
        else if(match){
            return dp[i][j] = solveMem(s, p , i + 1, j + 1, dp);
        }
        else{
            return dp[i][j] = false;
        }
    }

    bool isMatch(string s, string p) {
//        return solve(s, p, 0, 0);
        vector<vector<int>> dp(s.length() + 1, vector<int> (p.length() + 1, - 1));
        return solveMem(s, p, 0, 0, dp);
    }
};