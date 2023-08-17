class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        goal += goal;
        
        auto it = goal.find(s);
        if(it != string::npos){
            return true;
        }
        return false;
    }
};