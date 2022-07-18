class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> m;
        unordered_map<string, char> n;
        int j = 0;
        for (int i = 0; i < pattern.size(); ++i) {
            if(i <= pattern.size() -1 && j >= s.size()){
                return false;
            }
            string word;
            while(j < s.length() && s[j] != ' '){
                word += s[j];
                j++;
            }
            j++;
            if(m.count(pattern[i]) == 0){
                m.insert(pair<char,string>(pattern[i], word));
            }
            else{
                if(m[pattern[i]] != word){
                    return false;
                }
            }
            if(n.count(word) == 0){
                n.insert(pair<string,char>(word, pattern[i]));
            }
            else{
                if (n[word] != pattern[i]){
                    return false;
                }
            }
        }
        if(j <= s.size() - 1){
            return false;
        }
        return true;
    }
};