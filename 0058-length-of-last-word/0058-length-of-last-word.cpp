class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int currentlength = 0;
        int i = 0;
        while (i < s.length()) {
            if(s.at(i) == ' '){
                while (i < s.length() && s.at(i) == ' ')
                    i++;
                ans = currentlength;
                currentlength = 0;
            }
            else{
                currentlength++;
                i++;
            }
        }

        if (currentlength != 0){
            ans = currentlength;
        }
        return ans;
    }
};