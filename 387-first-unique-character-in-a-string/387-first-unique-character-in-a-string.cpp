class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> indices(26, -1);
        vector<int> alpahbetCounts(26, 0);
        for (int i = 0; i < s.length(); ++i) {
            int val = s.at(i) - 'a';
            alpahbetCounts[val]++;
            if(indices[val] == -1){
                indices[val] = i;
            }
        }
        int minIndexOFUniqueAlphabet = INT_MAX;
        for (int i = 0; i < 26; ++i) {
            if(alpahbetCounts[i] == 1){
                minIndexOFUniqueAlphabet = min(minIndexOFUniqueAlphabet, indices[i]);
            }
        }
        if(minIndexOFUniqueAlphabet == INT_MAX){
            return -1;
        }
        return minIndexOFUniqueAlphabet;
    }
};