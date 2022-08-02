class Solution {
public:
    string removeDuplicates(string s) {
        bool duplicateAdjacentFound = false;
        while (true){
            int i = 1;
            while (i < s.length()) {
                if(s.at( i - 1) == s.at(i)){
                    s.erase(i - 1, 2);
                    duplicateAdjacentFound = true;
                    i -= 2;
                    if(i < 0){
                        i = 0;
                    }
                }
                i++;
            }
            if (!duplicateAdjacentFound) {
                break;
            }
            duplicateAdjacentFound = false;
        }
        return s;
    }
};