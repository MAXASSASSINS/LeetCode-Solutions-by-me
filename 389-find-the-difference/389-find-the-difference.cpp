class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> vec(26,0);
        for (int i = 0; i < s.length(); ++i) {
            int val = s.at(i) - 'a';
            vec[val]++;
        }
        for (int i = 0; i < t.length(); ++i) {
            int val = t.at(i) - 'a';
            vec[val]--;
        }
        for (int i = 0; i < 26; ++i) {
            if(vec.at(i) == -1){
                return char(i + 'a');
            }
        }
        return '.';
    }
};