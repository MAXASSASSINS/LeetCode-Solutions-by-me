class Solution {
public:
    void convertNumToArray(vector<int> &ans, int number){
        if(number == 0){
            return;
        }
        convertNumToArray(ans,number / 10);
        int rem = number % 10;
        ans.push_back(rem);
    }

    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> num2, ans;
        int carry = 0;
        convertNumToArray(num2, k);
        int p1 = num.size() - 1;
        int p2 = num2.size() - 1;
        while(p1 >= 0 && p2 >= 0){
            int val = num[p1] + num2[p2] + carry;
            if(val >= 10){
                carry = 1;
            }
            else{
                carry = 0;
            }
            p1--;
            p2--;
            ans.push_back(val % 10);
        }
        while (p1 >= 0){
            int val = num[p1] + carry;
            if(val >= 10){
                carry = 1;
            }
            else{
                carry = 0;
            }
            p1--;
            ans.push_back(val % 10);

        }
        while (p2 >= 0){
            int val = num2[p2] + carry;
            if(val >= 10){
                carry = 1;
            }
            else{
                carry = 0;
            }
            p2--;
            ans.push_back(val % 10);
        }
        if(carry == 1){
            ans.push_back(1);
        }
        int st = 0;
        int en = ans.size() - 1;
        while (st < en){
            swap(ans[st], ans[en]);
            st++;
            en--;
        }
        return ans;
    }
};