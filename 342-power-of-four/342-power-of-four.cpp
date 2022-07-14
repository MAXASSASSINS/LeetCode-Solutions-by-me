class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0)
            return false;
        double val = log2(n) / 2;
        return val - int(val) == 0;
    }
};