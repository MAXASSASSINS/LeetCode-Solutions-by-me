class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s, t;
        for(auto str: word1){
            s += str;
        }
        for(auto str: word2){
            t += str;
        }
        
        return s == t;
        
    }
};