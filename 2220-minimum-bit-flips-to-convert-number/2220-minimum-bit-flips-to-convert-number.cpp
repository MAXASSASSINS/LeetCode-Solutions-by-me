class Solution {
public:
    int minBitFlips(int start, int goal) {
        bitset<32> x(start);
        bitset<32> y(goal);
        
        int cnt = 0;
        for(int i = 0; i < 32; i++){
            if(x[i] != y[i]){
                cnt++;
            }
        }
        
        return cnt;
    }
};