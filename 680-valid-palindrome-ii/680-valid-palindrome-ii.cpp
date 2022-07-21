class Solution {
public:
    bool isValidPalindrome(string s){
        int low = 0;
        int high = s.length() - 1;
        while (low < high){
            if(s.at(low) != s.at(high)){
                return false;
            }
            low++;
            high--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int low = 0;
        int high = s.length() - 1;
        while (low < high){
            if(s.at(low) == s.at(high)){
                low++;
                high--;
            }
            else{
                string previousS = s;
                string temp = s.erase(low, 1);
                cout<<temp<<endl;
                s = previousS;
                string temp2 = s.erase(high, 1);
                cout<<temp2<<endl;
                s = previousS;
                if(isValidPalindrome(temp) || isValidPalindrome(temp2)){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};