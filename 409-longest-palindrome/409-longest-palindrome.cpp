class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> small(26,0);
        vector<int> large(26, 0);
        for (int i = 0; i < s.length(); ++i) {
            int val;
            if(s.at(i) >= 'a'){
                val = s.at(i) - 'a';
                small[val]++;
            }
            else{
                val = s.at(i) - 'A';
                large[val]++;
            }
        }
        int length = 0;
        for (int i = 0; i < 26; ++i) {
            if(small.at(i) % 2 == 0){
                length += small.at(i);
                small.at(i) = 0;
            }
            else{
                length += (small.at(i)/2) * 2;
                small.at(i) = 1;
            }
            if(large.at(i) % 2 == 0){
                length += large.at(i);
                large.at(i) = 0;
            }
            else{
                length += (large.at(i)/2) * 2;
                large.at(i) = 1;
            }
        }
        for (int i = 0; i < 26; ++i) {
            if(small.at(i) == 1 || large.at(i) == 1){
                length++;
                break;
            }

        }
        return length;
    }
};