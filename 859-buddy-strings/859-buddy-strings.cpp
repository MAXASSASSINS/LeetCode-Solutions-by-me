class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(goal.length() != s.length()){
            return false;
        }
        int st = 0;
        int en = s.length() - 1;
        if(s == goal){
            sort(s.begin(), s.end());
            for (int i = 1; i < s.length(); ++i) {
                if(s.at(i - 1) == s.at(i)){
                    return true;
                }
            }
            return false;
        }
        for (int i = 0; i < goal.length(); ++i) {
            if(s.at(i) != goal.at(i)){
                st = i;
                break;
            }
        }
        for (int i = goal.length() - 1; i >= 0; --i) {
            if(s.at(i) != goal.at(i)){
                en = i;
                break;
            }
        }
        swap(s.at(st), s.at(en));
        return s == goal;
    }
};