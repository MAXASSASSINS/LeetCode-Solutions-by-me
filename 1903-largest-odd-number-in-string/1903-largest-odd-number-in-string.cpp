class Solution {
public:
    string largestOddNumber(string num) {
        string ans;
        int n = num.length();
        int idx = -1;
        for(int i = n - 1; i >= 0; i--){
            int x = num[i] - '0';
            if(x % 2 == 1){
                idx = i;
                break;
            }
        }
        
        if(idx == -1) return ans;
        
        ans = num.substr(0, idx + 1);
        return ans;
    }
};