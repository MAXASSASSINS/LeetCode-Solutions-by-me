class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = '-';
        int minDiff = INT_MAX;
        for (int i = 0; i < letters.size(); ++i) {
            if(target < letters[i]){
                int diff = letters[i] - target;
                if(diff < minDiff){
                    ans = letters[i];
                    minDiff = diff;
                }
            }
        }
        if(ans != '-'){
            return ans;
        }
        else{
            char temp = letters[0];
            for (int i = 1; i < letters.size(); ++i) {
                if(temp > letters[i]){
                    temp = letters[i];
                }
            }
            ans = temp;
        }
        return ans;
    }
};