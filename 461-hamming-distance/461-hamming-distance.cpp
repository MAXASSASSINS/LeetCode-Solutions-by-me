class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        bitset<32> num1(x);
        bitset<32> num2(y);
        for (int i = 0; i < 32; ++i) {
            if(num1.test(i) != num2.test(i)){
                count++;
            }
        }
        return count;
    }
};