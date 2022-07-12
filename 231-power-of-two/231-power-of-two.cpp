class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        double val = log2(n);
        return val - int(val) == 0;
    }
};