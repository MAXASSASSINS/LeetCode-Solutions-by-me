class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int maxLength = max(str1.length(), str2.length());
        int minLength = min(str1.length(), str2.length());
        string ans;
        string temp;
        int i = 0;
        while (temp.size() != minLength){
            temp += str1.at(i);
            i++;
            string temp2 = temp;
            bool equaltoStr1 = false;
            bool equaltoStr2 = false;
            while (temp2.size() < maxLength + 1){
                if(temp2 == str2){
                    equaltoStr2 = true;
                }
                if(temp2 == str1){
                    equaltoStr1 = true;
                }
                if(temp2.size() < str2.size() && temp2 != str2.substr(0,temp2.size())){
                    break;
                }
                if(temp2.size() < str1.size() && temp2 != str1.substr(0, temp2.size())){
                    break;
                }
                temp2 += temp;


            }
            if(equaltoStr1 && equaltoStr2){
                ans = temp;
            }
        }
        return ans;
    }
};