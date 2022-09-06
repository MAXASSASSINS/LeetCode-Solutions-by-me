class Solution {
public:
    string longestPalindrome(string s) {
        int maxLength = INT_MIN;
        string ans;
        for (int i = 0; i < s.length(); ++i) {
            int length = 1;
            int low = i - 1;
            int high = i + 1;
            while (low >= 0 && high < s.length()){
                if (s[low] == s[high]){
                    low--;
                    high++;
                    length += 2;
                }
                else{
                    break;
                }
            }
            if (length > maxLength){
                ans = s.substr(low + 1, high - low - 1);
                maxLength = length;
            }
        }

        for (int i = 1; i < s.length(); ++i) {
            if(s[i] == s[i - 1]){
                int low = i - 2;
                int high =  i + 1;
                int length = 2;
                while (low >= 0 && high < s.length()){
                    if (s[low] == s[high]){
                        low--;
                        high++;
                        length += 2;
                    }
                    else{
                        break;
                    }
                }
                if (length > maxLength){
                    ans = s.substr(low + 1, high - low - 1);
                    maxLength = length;
                }
            }
        }
        return ans;
    }


};