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
        long long even = 0;
        if(n % 2 == 0) even = n / 2;
        else even = n/2 + 1;
        long long  odd = n - even;
        
        int po = 4;
        int pe = 5;
        int modulo = 1e9 + 7;
        long long ans = 0;
        
        
        long long f = pow(4, odd, modulo) % modulo;
        long long s = pow(5, even, modulo) % modulo;
        
        ans = (f * s) % modulo;
        cout<<f<<"\t"<<s;
        return (int)ans;
    }
};