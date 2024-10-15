class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.length();
        int n0 = 0, n1 = 0;
        
        for(auto c: s){
            if(c == '0'){
                n0++;
            }
            else{
                n1++;
            }
        }
        
        long long res = 0;
        
        int j = n0;
        int i = 0;
        
        while(i < n0 && j < n){
            if(s[i] == '0'){
                i++;
            }
            else if(s[j] == '1'){
                j++;
            }
            else{
                res += j - i;
                j++;
                i++;
            }
        }
        
        return res;
    }
};