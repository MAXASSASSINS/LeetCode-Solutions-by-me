class Solution {
public:
    int fib(int n) {
        if(n <= 1){
            return n;
        }
        int last = 1; int secondlast = 0;
        int sum = 1;
        for (int i = 2; i <= n; ++i) {
            sum = last + secondlast; 
            secondlast = last;
            last = sum;
        }
        return sum;
    }
};