class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = 0;
        int j = 0;
        while (i < s.length() && j < t.length()){
            if(s.at(i) == '#'){
                if(i - 1 >= 0){
                    s.erase(i - 1, 2);
                    i-=2;
                }
                else{
                    s.erase(i, 1);
                    i--;
                }
            }
            if(t.at(j) == '#'){
                if(j - 1 >= 0){
                    t.erase(j - 1, 2);
                    j-=2;
                }
                else{
                    t.erase(j, 1);
                    j--;
                }
            }
            i++;
            j++;
        }
        while (i < s.length()){
            if(s.at(i) == '#'){
                if(i - 1 >= 0){
                    s.erase(i - 1, 2);
                    i-=2;
                }
                else{
                    s.erase(i, 1);
                    i--;
                }
            }
            i++;
        }
        while (j < t.length()){
            if(t.at(j) == '#'){
                if(j - 1 >= 0){
                    t.erase(j - 1, 2);
                    j-=2;
                }
                else{
                    t.erase(j, 1);
                    j--;
                }
            }
            j++;
        }
        return s == t;
    }
};