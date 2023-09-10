class Solution {
public:
    int countOrders(int n) {
        int mod = 1e9 + 7;
        long long ans = 1;
        
        for(int i = (2 * n) - 1; i >= 1; i-=2){
            ans *= i;
            ans %= mod;
        }
        
        long long fact = 1;
        for(int i = 2; i <= n; i++){
            fact *= i;
            fact %= mod;
        }
        
        ans *= fact;
        ans %= mod;
        return int(ans);
    }
};