class Solution {
public:
    int minOperations(string s) {
        int ez = 0;
        int eo = 0;
        int oz = 0;
        int oo = 0;
        
        int n = s.length();
        for(int i = 0; i < n; i+=2){
            if(s[i] == '0') ez++;
            else eo++;
        }
        
        for(int i = 1; i < n; i+=2){
            if(s[i] == '0') oz++;
            else oo++;
        }
    
        return min(n - oz - eo, n - oo - ez);
        
    }
};