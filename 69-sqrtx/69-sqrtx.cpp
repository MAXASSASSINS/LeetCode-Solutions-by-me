class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1){
            return x;
        }
        long int i = 0;
        while(i <= x/2) {
            if(i * i > x){
                return int(i - 1);
            }
            i++;
        }
        return int(i - 1);
    }
};