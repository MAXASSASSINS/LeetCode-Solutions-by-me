class Solution {
public:
    bool isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            return true;
        }
        return false;
    }
    
    int maxVowels(string s, int k) {
        int count = 0;
        for(int i = 0; i < k; i++){
            char c = s[i];
            if(isVowel(c)) count++;
        }
        
        int ans = count;
        
        for(int i = k; i < s.length(); i++){
            if(isVowel(s[i - k])){
                count--;
            }
            if(isVowel(s[i])){
                count++;
            }
            ans = max(ans, count);
            cout<<ans<<"\t";
            
        }
        
        return ans;
    }
};