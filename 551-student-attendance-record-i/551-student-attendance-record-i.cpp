class Solution {
public:
    bool checkRecord(string s) {
        return s.find("LLL") == s.npos && std::count(s.begin(), s.end(),'A') < 2;
    }
};