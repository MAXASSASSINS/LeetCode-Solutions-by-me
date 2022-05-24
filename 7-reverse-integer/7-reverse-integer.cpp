class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        bool xIsNegative = false;
        if (x < 0){
            xIsNegative = true;
            if (x == INT_MIN)
                return 0;
            x *= -1;
        }
        while (x != 0){
            if(ans <= INT_MAX/10)
                ans *= 10;
            else
                return 0;
            if(ans <= INT_MAX - x % 10)
                ans += x % 10;
            else
                return 0;

            x /= 10;
        }

        if (xIsNegative)
            ans *= -1;

        return  ans;
    }
};