class Solution {
public:
    string reverseWords(string s) {
        string t;
        int n = s.length();
        int i = n - 1;
        while(i >= 0){
            while(i >= 0 && s[i] == ' '){
                i--;
            }
            string temp;
            while(i >= 0 && s[i] != ' '){
                temp += s[i];
                i--;
            }
            cout<<temp<<endl;
            reverse(temp.begin(), temp.end());
            if(!temp.empty()){
                t += temp;
                t += ' ';  
            }
        }
        t.pop_back();
        return t;

    }
};