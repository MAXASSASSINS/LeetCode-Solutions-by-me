class Solution {
public:
    
    bool checkPossible(string &s, string &t){
        if(s.length() != t.length() + 1) return false;
        
        int fi = 0;
        int sec = 0;
        
        while(fi < s.length()){
            if(s[fi] == t[sec]){
                fi++;
                sec++;
            }
            else{
                fi++;
            }
        }
        
        if(fi == s.length() && sec == t.length()) return true;
        return false;
    }
    
    static bool cmp(string &s1, string &s2){
        return s1.length() < s2.length();
    }
    
    int solveTab2(vector<string> &words){
        int n = words.size();
        vector<int> dp(n, 1);
        
        sort(words.begin(), words.end(), cmp);
        
        for(int index = 0; index < n; index++){
            for(int prev = 0; prev < index; prev++){
                if(checkPossible(words[index], words[prev])){
                    dp[index] = max(dp[index], dp[prev] + 1);
                }
            }
        }
        
        int maxi = INT_MIN;
        for(auto x: dp){
            maxi = max(maxi, x);
        }
        
        return maxi;
    }
    int longestStrChain(vector<string>& words) {
        return solveTab2(words);   
    }
};