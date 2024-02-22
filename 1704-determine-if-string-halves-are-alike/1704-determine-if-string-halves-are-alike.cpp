class Solution {
    bool isVowel(char c){
        c = tolower(c);
        switch (c){
            case 'a': case 'e': case 'i': case 'o': case 'u':
                return true;
        }
        return false;
    }
public:
    bool halvesAreAlike(string s) {
        int n = s.length() / 2;
        int count1 = 0;
        int count2 = 0;
    
        for(int i = 0; i < n; i++){
            if(isVowel(s.at(i))){
                count1++;
            }
            if(isVowel(s.at(i + n))){
                count2++;
            }
        }

        cout<<count1<<" "<<count2<<endl;

        return count1 == count2;
    }
};