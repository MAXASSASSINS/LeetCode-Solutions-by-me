class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int n = s.length();
        for(int i = 0; i < n; i++){
            int j = i - 1;
            int k = i + 1;
            while(j >= 0 && k < n && s[j] == s[k]){
                j--;
                k++;
            }
            if(ans.length() < k - j - 1){
                ans = s.substr(j + 1, k - j - 1);
            }
        }
        
        for(int i = 0; i < n - 1; i++){
            if(s[i] == s[i + 1]){
                int j = i - 1;
                int k = i + 2;
                while(j >= 0 && k < n && s[j] == s[k]){
                    j--;
                    k++;
                }
                if(ans.length() < k - j - 1){
                    ans = s.substr(j + 1, k - j - 1);
                }
            }
        }
        
        return ans;
    }
};