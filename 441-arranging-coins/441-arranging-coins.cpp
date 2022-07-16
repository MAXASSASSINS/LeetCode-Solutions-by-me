class Solution {
public:
    int arrangeCoins(int n) {
        int maxMid = INT_MIN;
        int st = 1;
        int en = n;
        while (st <= en){
            int mid = st + (en - st)/2;
            double val = double (mid + 1)/2;
            if(val > (double)n/mid){
                en = mid - 1;
            }
            else if(val < (double)n/mid){
                st = mid + 1;
                maxMid = max(mid, maxMid);
            }
            else{
                return mid;
            }
        }
        return maxMid;
    }
};