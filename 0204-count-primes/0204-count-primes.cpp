class Solution {
public:
    
    int countPrimes(int n) {
        if(n == 0 || n == 1) return 0;
        vector<bool> vec(n, true);
        vec[0] = false;
        vec[1] = false;
        
        for(int i = 2; i < n; i++){
            if(vec[i]){
                for(long long j = (long long)i * i; j < n; j += i){
                    vec[j] = false;
                }
            }
        }
        
        int ans = 0;
        for(auto x: vec){
            if(x) ans++;
        }
        
        return ans;
    }
};