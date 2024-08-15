class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> vec(3);
        
        for(auto b: bills){
            if(b == 5){
                vec[0]++;
            }
            else if(b == 10){
                vec[1]++;
                vec[0]--;
                if(vec[0] < 0) return false;
            }
            else{
                vec[2]++;
                if(vec[1] > 0){
                    vec[1]--;
                    vec[0]--;
                }
                else{
                    vec[0] -= 3;
                }
                if(vec[0] < 0) return false;
            }
        }
        
        return true;
    }
};