class Solution {
public:
    bool isVowel(char c){
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    string sortVowels(string s) {
        map<char, int> m;
        for(auto c: s){
            if(isVowel(c)){
                m[c]++;
            }
        }
        
        auto it = m.begin();
        for(int i = 0; i < s.length(); i++){
            if(isVowel(s[i])){
                s[i] = it->first;
                it->second--;
                if(it->second == 0) it++;
            }
        }
        
        return s;
    }
};