class Solution {
public:
    long long pow(long long n, long long m, int modulo){
        if(m == 0) return 1;
        if(m % 2 == 0){
            long long temp = (pow(n, m/2, modulo)) % modulo;
            temp = (temp * temp)% modulo;
            return temp;
        }
        else{
            return ((n * pow(n, m - 1, modulo))%modulo);
        }
    }
    int countGoodNumbers(long long n) {
        long long odd = n / 2;
        long long even = n / 2 + n % 2;
        int mod = 1e9 + 7;
        return (pow(5, even, mod) * pow(4, odd, mod)) % mod;
    }
};