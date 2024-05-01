class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx = -1;
        for(int i = 0; i < word.length(); i++){
            if(ch == word[i]){
                idx = i;
                break;
            }
        }
        
        if(idx == -1) return word;
        
        string s = word.substr(0, idx + 1);
        string t = word.substr(idx + 1, word.length() - idx - 1);
        
        reverse(s.begin(), s.end());
        
        return s + t;
        
    }
};