class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num <= 1)
            return true;
        int st = 2;
        int en = num /2;
        while (st <= en){
            int mid = st + (en - st)/2;
            if((double)mid  == (double)num / mid)
                return true;
            else if(mid > num / mid)
                en = mid - 1;
            else
                st = mid + 1;
        }
        return false;
    }
};