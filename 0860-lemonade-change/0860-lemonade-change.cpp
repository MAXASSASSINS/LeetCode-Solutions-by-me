class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count$5 = 0;
        int count$10 = 0;
        bool ans = true;
        for (int i = 0; i < bills.size(); ++i) {
            if(bills.at(i) == 5){
                count$5++;
            }
            else if(bills.at(i) == 10){
                count$10++;
                if(count$5 == 0){
                    ans = false;
                    break;
                }
                else{
                    count$5--;
                }
            }
            else{
                if(count$10 > 0 && count$5 > 0){
                    count$10--;
                    count$5--;
                }
                else if(count$5 >= 3){
                    count$5 -= 3;
                }
                else{
                    ans = false;
                    break;
                }
                
            }
        }
        return ans;
    }
};