class Solution {
public:
    string convertToBase7(int num) {
        string ans;
        bool numIsNegative = false;
        if(num == 0){
            return "0";
        }
        if(num < 0){
            numIsNegative = true;
            num *= -1;
        }
        while (num != 0){
            char c = num % 7 + '0';
            ans += c;
            num/=7;
        }
        if(numIsNegative){
            ans.push_back('-');
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};