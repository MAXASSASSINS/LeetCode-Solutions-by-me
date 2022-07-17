class Solution {
public:
    bool detectCapitalUse(string word) {
        bool allCapitals = false;
        bool allSmall = true;
        bool firstCapital = false;
        bool small =  false;
        if(isupper(word.at(0))){
            firstCapital = true;
        }

        if(firstCapital && word.length() == 1){
            return true;
        }
        for (int i = 1; i < word.length(); ++i) {
            if(isupper(word.at(i))){
                allSmall = false;
            }
            else{
                small = true;
            }
        }
        if (firstCapital && allSmall)
            return true;
        if(!firstCapital && allSmall)
            return true;
        if(firstCapital && !small){
            return true;
        }
        return false;

    }
};