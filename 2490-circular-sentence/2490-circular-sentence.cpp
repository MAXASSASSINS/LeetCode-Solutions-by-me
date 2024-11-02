class Solution {
public:
    bool isCircularSentence(string s) {
        int n = s.length();
        int i = 0;
        
        while(i < n){
            while(i < n && s[i] != ' '){
                i++;
            }
            if(i + 1 < n && s[i - 1] != s[i + 1]) return false;
            else if(i == n && s[n - 1] != s[0]) return false;
            i++;
        }
        
        return true;
    }
};