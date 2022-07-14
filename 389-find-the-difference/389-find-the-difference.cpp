class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            ans = ans ^ s.at(i);
        }
        for (int i = 0; i < t.length(); ++i) {
            ans = ans ^ t.at(i);
        }
        return ans;

    }
};