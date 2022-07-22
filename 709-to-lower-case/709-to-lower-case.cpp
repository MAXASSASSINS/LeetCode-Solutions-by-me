class Solution {
public:
    string toLowerCase(string s) {
        for (int i = 0; i < s.length(); ++i) {
            if(s.at(i) <= 'Z'){
                s.at(i) = tolower(s.at(i));
            }
        }
        return s;
    }
};