class Solution {
public:
    bool checkValidString(string s) {
        int mini = 0; 
        int maxi = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                mini++;
                maxi++;
            }
            else if(s[i] == ')'){
                mini > 0 ? mini-- : 0;
                maxi--;
            }
            else{
                mini > 0 ? mini-- : 0;
                maxi++;
            }
            
            if(maxi < 0) return false;
        }
        
        return mini == 0;
    }
};