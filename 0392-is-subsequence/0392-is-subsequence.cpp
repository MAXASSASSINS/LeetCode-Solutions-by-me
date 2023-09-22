class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(t.length() < s.length())
            return false;
        int i = 0, j = 0;
        while (i < s.length() && j < t.length()) {
            while(j < t.length() && t.at(j) != s.at(i)){
                j++;
            }
            if(j == t.length() - 1 && i != s.length() - 1){
                return false;
            }
            if(i < s.length() && j < t.length() && s.at(i) == t.at(j)){
                i++;
                j++;
            }
        }
        return i == s.length();
    }
};