class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count1s = 0;
        while (n != 0){
            if(n % 2 == 0){
                n /= 2;
            }
            else{
                count1s++;
                n -= 1;
            }
        }
        return count1s;
    }
};