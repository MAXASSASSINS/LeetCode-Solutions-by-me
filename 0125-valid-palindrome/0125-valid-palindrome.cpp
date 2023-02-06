class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int h = s.length() - 1;
        while(l <= h){
            while(l < s.length() && !isalnum(s[l])) l++;
            if(l == s.length()) return true;
            while(h >= 0 && !isalnum(s[h])) h--;
            if(h < 0) return true;
            
            if(tolower(s[l]) != tolower(s[h])) return false;
            l++;
            h--;
        }
        
        return true;
    }
};