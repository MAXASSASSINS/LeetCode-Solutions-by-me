class Solution {
public:
        
    int minimumOperations(string num) {
        int n = num.length();
        int ans = n;
        for(auto x: num){
            if(x == '0'){ 
                ans = n - 1;
                break;
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int val = (num[i] - '0') * 10 + (num[j] - '0');
                if(val % 25 == 0){
                    int skip = (j - i - 1) + (n - j - 1);
                    ans = min(ans, skip);
                }
            }
        }
        return ans;
        
    }
};