class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int cnt = numBottles;
        int empty = numBottles;
        int filled = 0;
        
        while(empty >= numExchange){
            filled = empty / numExchange;
            cnt += filled;
            empty = filled + (empty % numExchange);
        }
        return cnt;
    }
};