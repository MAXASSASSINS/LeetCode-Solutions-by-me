class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while (columnNumber > 0) {
            int val = columnNumber % 26;
            if(val == 0){
                ans.push_back('Z');
                if (columnNumber == 26){
                    break;
                }
                columnNumber /= 26;
                columnNumber -= 1;
                continue;
            }
            char c = char(val + 'A' - 1);
            ans.push_back(c);
            columnNumber /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};