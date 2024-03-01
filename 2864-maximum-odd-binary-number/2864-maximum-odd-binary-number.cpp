class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int len = s.length();
        int cntOne = 0;
        for(int i = 0; i < len; i++){
            if(s[i] == '1') cntOne++;
        }
        
        string t;
        for(int i = 0; i < cntOne - 1; i++){
            t += '1';
        }
        for(int i = 0; i < len - cntOne; i++){
            t += '0';
        }
        t += '1';

        return t;
    }
};