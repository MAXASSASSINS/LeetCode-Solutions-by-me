class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;
        bool isNegative = false;
        while(s[i] == ' ') i++;
        if(s[i] == '+') i++;
        else if(s[i] == '-') {
            isNegative = true;
            i++;
        }
        // if(!isdigit(s[i])) return 0;
        
        while(i < n && s[i] == '0') i++;
        
        string t;
        while(i < n && isdigit(s[i])){
            t += s[i];
            i++;
        }
        
        cout<<t<<endl;
        
        long long ans = 0;
        for(auto c: t){
            if(ans > INT_MAX) break;
            ans *= 10;
            ans += c - '0';
        }
        
        
        if(isNegative){
            ans *= -1;
            if(ans < INT_MIN){
                ans = INT_MIN;
            }
        }
        else{
            if(ans > INT_MAX){
                ans = INT_MAX;
            }
        }
        
        return int(ans);
    }
};