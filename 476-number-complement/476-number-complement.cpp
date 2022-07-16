class Solution {
public:
    int findComplement(int num) {
        bitset<32> n(num);
        int count = 0;
        while (num != 0){
            num /= 2;
            count++;
        }
        for (int i = 0; i < count; ++i) {
            n.flip(i);
        }
        return (int)(n.to_ulong());
    }
};