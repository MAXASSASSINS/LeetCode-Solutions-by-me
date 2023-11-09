class Solution {
public:
    long long calc(int n, int mod){
        long long res = (1LL * n * n) % mod + (1 * n)%mod - ((1LL * n*(n + 1))/2)%mod;
        return res % mod;
    }
    
    int countHomogenous(string s) {
        int mod = 1e9 + 7;
        int ans = 0;
        int n = s.length();
        
        int i = 0;
        while(i < n){
            int j = i + 1;
            while(j < n && s[j] == s[i]) j++;
            int count = j - i;
            cout<<count<<"\t";
            ans += calc(count, mod) % mod;
            i = j;
        }
        
        
        return ans;
    }
};