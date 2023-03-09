class Solution {
public:
    string largestOddNumber(string num) {
        string ans;
        string temp;
        for(auto c: num){
            temp += c;
            if((c - 48) % 2 == 1){
                ans = temp;
            }
        }
        
        
        return ans;
    }
};