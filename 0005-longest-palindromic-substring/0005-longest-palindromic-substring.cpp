class Solution {
public:
    string longestPalindrome(string s) {
        int ans = 0;
        string res;
        for(int i = 0; i < s.length(); i++){
            string odd = expand(s, i, i);
            string even = expand(s, i, i + 1);
            getMaxLengthPalindromicSubstring(odd, ans, res);
            getMaxLengthPalindromicSubstring(even, ans, res);
        }
        
        return res;
    }
    
    string expand(string s, int l, int r){
        while(l >= 0 && r < s.length()){
            if(s[l] != s[r]) break;
            l--;
            r++;
        }
        
        return s.substr(l + 1, r - l - 1);
    }
    
    void getMaxLengthPalindromicSubstring(string s, int &ans, string &res){
        if(s.length() > ans){
            ans = s.length();
            res = s;
        }
    }
};