class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();
        int i = 0;
        while(i < n && s[i] == '9'){
            i++;
        }
        
        while(i < n){
            char maxi = i;
            for(int j = n - 1; j > i; j--){
                if(s[maxi] < s[j]){
                    maxi = j;
                }
            }
            if(s[maxi] == s[i]){
                i++;
                continue;
            }
            swap(s[maxi], s[i]);
            break;
        }
        
        int res = stoi(s);
        
        return res;
        
    }
};