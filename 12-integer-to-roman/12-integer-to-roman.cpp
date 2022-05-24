class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        vector<string> romanSymbol = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        vector<int> value = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        int i = value.size() - 1;

        while (num != 0){
            int count = num / value.at(i);
            for (int j = 0; j < count; ++j) {
                ans += romanSymbol.at(i);
            }
            num %= value.at(i);
            i--;
        }
        return ans;
    }
};