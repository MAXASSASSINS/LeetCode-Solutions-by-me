class Solution {
public:
    bool checkRecord(string s) {
        int n = s.length();
        bool late3ConsecutiveDays = false;
        int countAbsent = 0;
        for (int i = 0; i < n; ++i) {
            if(s.at(i) == 'A'){
                countAbsent++;
            }
        }
        for (int i = 0; i < n - 2; ++i) {
            if(s.at(i) == 'L'){
                if(s.at(i + 1) == 'L' && s.at(i + 2) == 'L'){
                    late3ConsecutiveDays = true;
                    break;
                }
            }
        }
        return !late3ConsecutiveDays && countAbsent < 2;
    }
};