class Solution {
public:
    string compressedString(string word) {
        string t;
        int i = 0, j = 0;
        int n = word.length();
        
        while(j < n){
            while(j < n && word[i] == word[j]){
                j++;
            }
            
            int len = j - i;
            while(len / 9 != 0){
                t += 9  + '0';
                t += word[i];
                len -= 9;
            }
            if(len > 0){
                t += len + '0';
                t += word[i];
            }
            i = j;
        }
        return t;
    }
};