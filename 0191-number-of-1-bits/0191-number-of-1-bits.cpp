class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n != 0){
            int mod = n % 2;
            if(mod == 1) cnt++;
            n /= 2;
        }
        
        return cnt;
    }
};