class Solution {
public:
    int countPrimes(int n) {
        if(n <= 1) return 0;
        vector<bool> primes(n, true);
        
        primes[0] = false;
        primes[1] = false;
        
        for(int i = 2; i < n; i++){
            if(primes[i] == true){
                int mul = i;
                for(int j = i + mul; j < n; j += mul){
                    primes[j] = false;
                }
            }
                
        }
        
        int count = 0;
        for(auto x: primes){
            if(x == true) count++;
        }
        
        return count;
    }
};