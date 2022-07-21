class Solution {
public:
    bool hasAlternatingBits(int n) {
        long int i = 1;
        while (i < n){
            if(i % 2 == 0){
                i = i * 2 + 1;
            }
            else{
                i *= 2;
            }
        }
        if(i == n){
            return true;
        }
        return false;

    }
};