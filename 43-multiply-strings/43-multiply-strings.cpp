class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int carry = 0;
        while (i >= 0 && j >= 0) {
            int n = int(num1.at(i) - '0');
            int m = int(num2.at(j) - '0');
            int res = n + m + carry;
            if (res >= 10) {
                carry = 1;
                res %= 10;
            } else {
                carry = 0;
            }
            i--;
            j--;
            ans.push_back(res + '0');
        }
        while (i >= 0) {
            int n = int(num1.at(i) - '0');
            int res = n + carry;
            if (res >= 10) {
                carry = 1;
                res %= 10;
            } else {
                carry = 0;
            }
            i--;
            ans.push_back(res + '0');
        }
        while (j >= 0) {
            int m = int(num2.at(j) - '0');
            int res = m + carry;
            if (res >= 10) {
                carry = 1;
                res %= 10;
            } else {
                carry = 0;
            }
            j--;
            ans.push_back(res + '0');
        }

        if (carry == 1) {
            ans.push_back(1 + '0');
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }

    string multiply(string num1, string num2) {
        vector<string> ans;
        int carry = 0;
        for (int i = num2.size() - 1; i >= 0; --i) {
            string s;
            for (int j = i + 1; j < num2.size(); ++j) {
                s.push_back('0');
            }
            carry = 0;
            int y = num2.at(i) - '0';
            for (int j = num1.size() - 1; j >= 0; --j) {
                int x = num1.at(j) - '0';
                int temp = x * y + carry;
                carry = temp / 10;
                temp %= 10;
                s.push_back(temp + '0');
            }
            if(carry != 0){
                s.push_back(carry + '0');
            }
            std::reverse(s.begin(), s.end());
            ans.push_back(s);
        }



        string result;
        for (int i = 0; i < ans.size(); ++i) {
            result = addStrings(result, ans.at(i));
        }
        if(result[0] == '0'){
            result = result.substr(0, 1);
        }
        return result;
    }
};