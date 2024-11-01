class Solution {
public:
    string makeFancyString(string s) {
        if(s.length() < 3) return s;
        string t = s.substr(0, 2);
        
        for(int i = 2; i < s.length(); i++){
            char c = s[i];
            int n = t.length();
            char prev = t[n - 1];
            char prevprev = t[n - 2];
            if(c == prev && c == prevprev){
                continue;
            }
            else{
                t.push_back(c);
            }
        }
        
        return t;
    }
};