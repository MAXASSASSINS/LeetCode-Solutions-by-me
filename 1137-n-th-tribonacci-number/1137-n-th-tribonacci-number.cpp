class Solution {
public:
    int tribonacci(int n) {
        int f = 0;
        int s = 1;
        int t = 1;
        if(n == 0){
            return f;
        }
        if(n <= 2){
            return s;
        }
        int ans = 0;
        ans = f + s + t;
        for (int i = 4; i <= n; ++i) {
            f = s;
            s = t;
            t = ans;
            ans = f + s + t;
        }
        return ans;
    }
};