class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> vec(26, 0);
        for (int i = 0; i < s.length(); ++i) {
            int index = s.at(i) - 'a';
            vec[index]++;
        }
        for (int i = 0; i < t.length(); ++i) {
            int index = t.at(i) - 'a';
            vec[index]--;
        }
        for (int i = 0; i < 26; ++i) {
            if(vec.at(i) != 0){
                return false;
            }
        }
        return true;
    }
};