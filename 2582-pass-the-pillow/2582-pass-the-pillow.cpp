class Solution {
public:
    int passThePillow(int n, int time) {
        time %= ((n - 1) * 2);
        if(time < n){
            return time + 1;
        }
        return 2*n - 1 - time;
    }
};