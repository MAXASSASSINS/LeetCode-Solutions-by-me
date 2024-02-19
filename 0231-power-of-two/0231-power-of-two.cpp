class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        double val = log2(n);
        double valInt = floor(val);
        if(val - valInt > 0) return false;
        return true;
    }
};