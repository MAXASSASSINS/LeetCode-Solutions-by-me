class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;
        while (i >= 0 && j >= 0){
            int n1 = a.at(i) - '0';
            int n2 = b.at(j) - '0';
            int sum = n1 + n2 + carry;
            if(sum == 2){
                carry = 1;
                sum = 0;
            }
            else if(sum == 3){
                carry = 1;
                sum = 1;
            }
            else {
                carry = 0;
            }
            ans.push_back(sum + '0');
            i--;
            j--;
        }
        while (i >= 0){
            int n1 = a.at(i) - '0';
            int sum = n1 + carry;
            if(sum >= 2){
                carry = 1;
                sum = 0;
            }
            else if(sum == 3){
                carry = 1;
                sum = 1;
            }
            else{
                carry = 0;
            }
            ans.push_back(sum + '0');
            i--;
        }
        while (j >= 0){
            int n2 = b.at(j) - '0';
            int sum = n2 + carry;
            if(sum >= 2){
                carry = 1;
                sum = 0;
            }
            else if(sum == 3){
                carry = 1;
                sum = 1;
            }
            else{
                carry = 0;
            }
            ans.push_back(sum + '0');
            j--;
        }
        if(carry == 1){
            ans.push_back(carry + '0');
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};