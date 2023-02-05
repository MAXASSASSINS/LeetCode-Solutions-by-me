class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        bool arr[n][n];
        
        string t;
        t += s[0];
        
        for(int gap = 0; gap < n; gap++){
            for(int i = 0, j = gap; j < n; i++, j++){
                if(gap == 0){
                    arr[i][j] = true;
                }
                else if(gap == 1){
                    if(s[i] == s[j]){
                        arr[i][j] = true;
                    }
                    else{
                        arr[i][j] = false;
                    }
                }
                else{
                    if(s[i] == s[j] && arr[i + 1][j - 1] == true){
                        arr[i][j] = true;
                    }
                    else{
                        arr[i][j] = false;
                    }
                }
                if(arr[i][j] == true && t.length() < gap + 1){
                    t = s.substr(i, j + 1 - i); 
                }
            }
        }
        
        return t;
        
    }
};